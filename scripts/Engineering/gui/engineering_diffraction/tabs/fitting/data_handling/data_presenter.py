# Mantid Repository : https://github.com/mantidproject/mantid
#
# Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
#     NScD Oak Ridge National Laboratory, European Spallation Source
#     & Institut Laue - Langevin
# SPDX - License - Identifier: GPL - 3.0 +

from Engineering.gui.engineering_diffraction.tabs.common import create_error_message
from mantid.simpleapi import logger
from mantidqt.utils.asynchronous import AsyncTask
from mantidqt.utils.observer_pattern import GenericObservable


class FittingDataPresenter(object):
    def __init__(self, model, view):
        self.model = model
        self.view = view
        self.worker = None

        self.row_numbers = TwoWayRowDict()  # {ws_name: table_row} and {table_row: ws_name}
        self.plotted = set()  # List of plotted workspace names

        # Connect view signals to local methods
        self.view.set_on_load_clicked(self.on_load_clicked)
        self.view.set_enable_button_connection(self._enable_load_button)
        self.view.set_on_remove_selected_clicked(self._remove_selected_tracked_workspaces)
        self.view.set_on_remove_all_clicked(self._remove_all_tracked_workspaces)
        self.view.set_on_table_cell_changed(self._handle_table_cell_changed)

        # Observable Setup
        self.plot_added_notifier = GenericObservable()
        self.plot_removed_notifier = GenericObservable()
        self.all_plots_removed_notifier = GenericObservable()

    def on_load_clicked(self):
        if self._validate():
            filenames = self._get_filenames()
            self._start_load_worker(filenames)

    def remove_workspace(self, ws_name):
        if ws_name in self.get_loaded_workspaces():
            removed = self.get_loaded_workspaces().pop(ws_name)
            self.plot_removed_notifier.notify_subscribers(removed)
            self.plotted.discard(ws_name)
            self._repopulate_table()

    def rename_workspace(self, old_name, new_name):
        loaded_workspaces = self.get_loaded_workspaces()
        if old_name in loaded_workspaces:
            ws = loaded_workspaces.pop(old_name)
            loaded_workspaces[new_name] = ws
            if old_name in self.plotted:
                self.plotted.remove(old_name)
                self.plotted.add(new_name)
            self._repopulate_table()

    def clear_workspaces(self):
        self.get_loaded_workspaces().clear()
        self.plotted.clear()
        self.row_numbers.clear()
        self._repopulate_table()

    def replace_workspace(self, name, workspace):
        if name in self.get_loaded_workspaces():
            self.get_loaded_workspaces()[name] = workspace
            if name in self.plotted:
                self.all_plots_removed_notifier.notify_subscribers()
            self._repopulate_table()

    def get_loaded_workspaces(self):
        return self.model.get_loaded_workspaces()

    def _start_load_worker(self, filenames):
        """
        Load one to many files into mantid that are tracked by the interface.
        :param filenames: Comma separated list of filenames to load
        """
        self.worker = AsyncTask(self.model.load_files, (filenames, ),
                                error_cb=self._on_worker_error,
                                finished_cb=self._emit_enable_button_signal,
                                success_cb=self._on_worker_success)
        self.worker.start()

    def _on_worker_error(self, _):
        logger.error("Error occurred when loading files.")
        self._emit_enable_button_signal()

    def _on_worker_success(self, _):
        if self.view.get_add_to_plot():
            self.plotted.update(self.model.get_last_added())
        self._repopulate_table()

    def _repopulate_table(self):
        """
        Populate the table with the information from the loaded workspaces.
        Will also handle any workspaces that need to be plotted.
        """
        self._remove_all_table_rows()
        self.row_numbers.clear()
        self.all_plots_removed_notifier.notify_subscribers()
        workspaces = self.get_loaded_workspaces()
        for i, name in enumerate(workspaces):
            try:
                run_no = self.model.get_sample_log_from_ws(name, "run_number")
                bank = self.model.get_sample_log_from_ws(name, "bankid")
                if bank == 0:
                    bank = "cropped"
                checked = name in self.plotted
                self._add_row_to_table(name, i, run_no, bank, checked)
            except RuntimeError:
                self._add_row_to_table(name, i)
            self._handle_table_cell_changed(i, 2)

    def _remove_selected_tracked_workspaces(self):
        row_numbers = self._remove_selected_table_rows()
        for row_no in row_numbers:
            ws_name = self.row_numbers.pop(row_no)
            removed = self.get_loaded_workspaces().pop(ws_name)
            self.plot_removed_notifier.notify_subscribers(removed)
            self.plotted.discard(ws_name)
        self._repopulate_table()

    def _remove_all_tracked_workspaces(self):
        self.clear_workspaces()
        self._remove_all_table_rows()

    def _handle_table_cell_changed(self, row, col):
        if col == 2 and row in self.row_numbers:  # Is from the plot check column
            ws = self.model.get_loaded_workspaces()[self.row_numbers[row]]
            ws_name = self.row_numbers[row]
            if self.view.get_item_checked(row, col):  # Plot Box is checked
                self.plot_added_notifier.notify_subscribers(ws)
                self.plotted.add(ws_name)
            else:  # Plot box is unchecked
                self.plot_removed_notifier.notify_subscribers(ws)
                self.plotted.discard(ws_name)

    def _enable_load_button(self, enabled):
        self.view.set_load_button_enabled(enabled)

    def _emit_enable_button_signal(self):
        self.view.sig_enable_load_button.emit(True)

    def _get_filenames(self):
        return self.view.get_filenames_to_load()

    def _is_searching(self):
        return self.view.is_searching()

    def _files_are_valid(self):
        return self.view.get_filenames_valid()

    def _validate(self):
        if self._is_searching():
            create_error_message(self.view, "Mantid is searching for files. Please wait.")
            return False
        elif not self._files_are_valid():
            create_error_message(self.view, "Entered files are not valid.")
            return False
        return True

    def _add_row_to_table(self, ws_name, row, run_no=None, bank=None, checked=False):
        words = ws_name.split("_")
        if run_no is not None and bank is not None:
            self.view.add_table_row(run_no, bank, checked)
            self.row_numbers[ws_name] = row
        elif len(words) == 4 and words[2] == "bank":
            logger.notice("No sample logs present, determining information from workspace name.")
            self.view.add_table_row(words[1], words[3], checked)
            self.row_numbers[ws_name] = row
        else:
            logger.warning(
                "The workspace '{}' was not in the correct naming format. Files should be named in the following way: "
                "INSTRUMENT_RUNNUMBER_bank_BANK. Using workspace name as identifier.".format(ws_name)
            )
            self.view.add_table_row(ws_name, "N/A", checked)
            self.row_numbers[ws_name] = row

    def _remove_table_row(self, row_no):
        self.view.remove_table_row(row_no)

    def _remove_selected_table_rows(self):
        return self.view.remove_selected()

    def _remove_all_table_rows(self):
        self.view.remove_all()


class TwoWayRowDict(dict):
    """
    Two way dictionary used to map rows to workspaces and vice versa.
    """
    def __setitem__(self, key, value):
        if key in self:
            del self[key]
        if value in self:
            del self[value]
        dict.__setitem__(self, key, value)
        dict.__setitem__(self, value, key)

    def __delitem__(self, key):
        dict.__delitem__(self, self[key])
        dict.__delitem__(self, key)

    def pop(self, key):
        value = self[key]
        self.__delitem__(key)
        return value

    def __len__(self):
        return dict.__len__(self) / 2

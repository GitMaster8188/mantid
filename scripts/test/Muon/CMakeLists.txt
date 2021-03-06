# Tests for Muon GUIs

set ( TEST_PY_FILES
   workspaceNaming_test.py
   FFTModel_test.py
   FFTPresenter_test.py
   fft_presenter_context_interaction_test.py
   fitting_tab_widget/workspace_selector_dialog_presenter_test.py
   fitting_tab_widget/fitting_tab_presenter_test.py
   fitting_tab_widget/fitting_tab_model_test.py
   seq_fitting_tab_widget/seq_fitting_tab_presenter_test.py
   seq_fitting_tab_widget/sequential_table_test.py
   fit_information_test.py
   fit_parameters_test.py
   fitting_context_test.py
   home_instrument_widget_test.py
   plotting_widget_test.py
   plotting_widget_tiled_test.py
   plotting_widget_freq_test.py
   plotting_widget_model_test.py
   external_plotting_model_test.py
   workspace_finder_test.py
   home_runinfo_presenter_test.py
   list_selector/list_selector_view_test.py
   list_selector/list_selector_presenter_test.py
   load_run_widget/loadrun_model_test.py
   load_run_widget/loadrun_presenter_current_run_test.py
   load_run_widget/loadrun_presenter_single_file_test.py
   load_run_widget/loadrun_presenter_multiple_file_test.py
   load_file_widget/loadfile_model_test.py
   load_file_widget/loadfile_presenter_single_file_test.py
   load_file_widget/loadfile_presenter_multiple_file_test.py
   load_file_widget/loadfile_view_test.py
   load_run_widget/loadrun_presenter_increment_decrement_test.py
   load_run_widget/loadrun_view_test.py
   loading_tab/loadwidget_presenter_test.py
   loading_tab/loadwidget_presenter_multiple_file_test.py
   loading_tab/loadwidget_presenter_failure_test.py
   phase_table_widget/phase_table_presenter_test.py
   phase_table_widget/phase_table_context_test.py
   frequency_domain_context_test.py
   grouping_tab/grouping_table_presenter_test.py
   grouping_tab/pairing_table_presenter_test.py
   grouping_tab/grouping_tab_presenter_test.py
   grouping_tab/pairing_table_group_selector_test.py
   grouping_tab/pairing_table_alpha_test.py
   MaxEntModel_test.py
   MaxEntPresenter_test.py
   max_ent_presenter_load_interaction_test.py
   muon_context_test.py
   muon_context_with_frequency_test.py
   muon_data_context_test.py
   muon_gui_context_test.py
   muon_group_pair_context_test.py
   results_tab_widget/results_tab_model_test.py
   results_tab_widget/results_tab_presenter_test.py
   transformWidget_test.py
   transform_widget_new_test.py
   utilities/muon_group_test.py
   utilities/muon_pair_test.py
   utilities/load_utils_test.py
   utilities/thread_model_test.py
   utilities/muon_workspace_wrapper_test.py
   utilities/muon_workspace_wrapper_directory_test.py
   utilities/muon_load_data_test.py
   utilities/muon_file_utils_test.py
   utilities/run_string_utils_operator_test.py
   utilities/run_string_utils_conversion_test.py
   help_widget_presenter_test.py
   xml_utils_test.py
   elemental_analysis/elemental_analysis_test.py
   elemental_analysis/name_generator_test.py
   elemental_analysis/detectors_presenter_test.py
   elemental_analysis/periodic_table_test.py
   elemental_analysis/peak_selector_view_test.py
   elemental_analysis/element_button_test.py
   elemental_analysis/periodic_combo_test.py
   elemental_analysis/periodic_list_test.py
   elemental_analysis/periodic_table_item_test.py
   elemental_analysis/lmodel_test.py
   elemental_analysis/load_model_test.py
)

# LoadWidgetModel_test.py, LoadWidgetPresenter_test.py and LoadWidgetView_test.py are currently not Qt5 compatible
set ( TEST_PY_FILES_QT4
   LoadWidgetPresenter_test.py
   LoadWidgetView_test.py
   FFTPresenter_test.py
   fft_presenter_context_interaction_test.py
   ADSHandler/workspace_naming_test.py
   fitting_tab_widget/workspace_selector_dialog_presenter_test.py
   fitting_tab_widget/fitting_tab_presenter_test.py
   fitting_tab_widget/fitting_tab_model_test.py
   seq_fitting_tab_widget/seq_fitting_tab_presenter_test.py
   seq_fitting_tab_widget/sequential_table_test.py
   fit_information_test.py
   fit_parameters_test.py
   fitting_context_test.py
   home_instrument_widget_test.py
   plotting_widget_test.py
   plotting_widget_tiled_test.py
   plotting_widget_freq_test.py
   external_plotting_model_test.py
   workspace_finder_test.py
   home_runinfo_presenter_test.py
   list_selector/list_selector_view_test.py
   list_selector/list_selector_presenter_test.py
   load_run_widget/loadrun_presenter_current_run_test.py
   load_run_widget/loadrun_presenter_single_file_test.py
   load_run_widget/loadrun_presenter_multiple_file_test.py
   load_file_widget/loadfile_presenter_single_file_test.py
   load_file_widget/loadfile_presenter_multiple_file_test.py
   load_file_widget/loadfile_view_test.py
   load_run_widget/loadrun_presenter_increment_decrement_test.py
   load_run_widget/loadrun_view_test.py
   loading_tab/loadwidget_presenter_test.py
   loading_tab/loadwidget_presenter_multiple_file_test.py
   loading_tab/loadwidget_presenter_failure_test.py
   phase_table_widget/phase_table_presenter_test.py
   grouping_tab/grouping_table_presenter_test.py
   grouping_tab/pairing_table_presenter_test.py
   grouping_tab/grouping_tab_presenter_test.py
   grouping_tab/pairing_table_group_selector_test.py
   grouping_tab/pairing_table_alpha_test.py
   MaxEntPresenter_test.py
   max_ent_presenter_load_interaction_test.py
   results_tab_widget/results_tab_presenter_test.py
   transformWidget_test.py
   transform_widget_new_test.py
   help_widget_presenter_test.py
   elemental_analysis/PeriodicTableModel_test.py
   elemental_analysis/PeriodicTablePresenter_test.py
   elemental_analysis/load_utils_test.py
)

check_tests_valid(${CMAKE_CURRENT_SOURCE_DIR} ${TEST_PY_FILES})

# Prefix for test name=PythonAlgorithms
set(PYUNITTEST_QT_API pyqt) # force to use qt4
pyunittest_add_test(${CMAKE_CURRENT_SOURCE_DIR} python.MuonQt4
${TEST_PY_FILES_QT4} ${})

set(PYUNITTEST_QT_API pyqt5) # force to use qt5
pyunittest_add_test(${CMAKE_CURRENT_SOURCE_DIR} python.MuonQt5
${TEST_PY_FILES})
unset(PYUNITTEST_QT_API)

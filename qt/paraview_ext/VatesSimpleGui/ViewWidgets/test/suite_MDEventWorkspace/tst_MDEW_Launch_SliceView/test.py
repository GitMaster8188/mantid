# Mantid Repository : https://github.com/mantidproject/mantid
#
# Copyright &copy; 2018 ISIS Rutherford Appleton Laboratory UKRI,
#   NScD Oak Ridge National Laboratory, European Spallation Source,
#   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
# SPDX - License - Identifier: GPL - 3.0 +
def main():
    source(findFile("scripts", "test_helpers.py"))
    source(findFile("scripts", "common_checks.py"))
    startApplication("MantidPlot")
    run_script("mdew_4D.py")

    workspace_name = "SEQ"
    get_workspace(workspace_name)
    activate_vsi()
    switch_mode("multiSlice")
    make_slice("xAxisWidget", 0.05)
    slice_number = 1
    activate_sv(slice_number)
    check_sv_opened(workspace_name, slice_number, True, "SliceView launched from MultiSlice mode for MDEW.")

    quit_program()
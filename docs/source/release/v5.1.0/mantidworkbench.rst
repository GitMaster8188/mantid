=======================
MantidWorkbench Changes
=======================

.. contents:: Table of Contents
   :local:

New
###

- The Advanced Plotting menu is now in Workbench. This enables creating surface and contour plots of three or more workspaces, and choosing which log value to plot against.

Improvements
############

.. figure:: ../../images/Plot1DSelectionDialog5-1.png
   :align: right

- The plot selection dialog now correctly shows the full range of valid spectra to plot, not just the min to max range.
- Tile plots are now reloaded correctly by project recovery.
- When you stop a script running in workbench it will now automatically attempt to cancel the algorithm the script is running, rather than wait for the current algorthm to end.
  This is similar to what Mantidplot does, and should result in the script stopping much sooner.
- Fixed an issue where some scripts were running slower if a  plot was open at the same time.
- The Help Menu now has an About screen that will pop up automatically on startup to provide links to the release notes and various other resources, and allow you to set some important setting such as Facility, instrument and accept usage tracing.
  You can choose to hide it until the next release.
- The axes tab in the figure options can now be used to set the limits, label, and scale of the z-axis on 3D plots.

- On 3D plots you can now double-click on the z-axis to change its limits or label.


Bugfixes
########

- Fixed a bug where setting columns to Y error in table workspaces wasn't working. The links between the Y error and Y columns weren't being set up properly.
- Fixed a crash when you selected a spectra to plot that was not present in a workspace.
- Fixed a crash when you defined a new Fit Function after deleting a plot.
- The scale of the color bars on colorfill plots of ragged workspaces now uses the maximum and minimum values of the data.
- Fixed a bug where setting columns to Y error in table workspaces wasn't working. The links between the Y error and Y columns weren't being set up properly
- Opening figure options on a plot with an empty legend no longer causes an unhandled exception.

:ref:`Release 5.1.0 <v5.1.0>`

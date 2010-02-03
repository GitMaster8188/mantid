###########################################
# applies unit conversion, detector convcy and grouping correction to a
# raw file and writes the result to a SPE file
###########################################
# To use this script outside Mantid plot copy the script out of the Code\Mantid\PythonAPI\scripts\Excitations
# directory and replace all |GUI_SET_*| with good values
# Used by MantidPlot if the script in is in Code\Mantid\PythonAPI\scripts\Excitations make a
# copy of the script if you want to change it or risk the MantidPlot interface not working
from mantidsimple import *
# import some Python scripts with functions we'd like to use
import CommonFunctions as common
import ConversionLib as conv

THISSCRIPT = 'Convert to Energy transfer'

# all |GUI_SET_*| are quantities set by the QT interface that runs this script, changing this symbols here will stop the setting being read in from the script
nameInOut = |GUI_SET_OUTWS|     # nameInOut is first used as an intermediate workspace and contains the output data at the end, it's renamed at the end

# this is a tuple and maybe set equal to one or many workspaces, they will be sumed
input = (|GUI_SET_RAWFILE_LIST|)
try:
#the new workspace will be able to be accessed via the pointer, pInOut, or its name, nameInout
  pInOut = common.LoadNexRaw(input[0], nameInOut)

#----Calculations start------------------
  # the string |GUI_SET_E| below is replaced by a value depending on what was entered on the user interface, either the value of the energy to use (in meV) or the string 'Run GEtEi'
  IncidentE = |GUI_SET_E|
  if IncidentE == 'Run GetEi':
    #?? 2 and 3 below are good for MARI, this needs to be changed in other instruments
    GetEiData = GetEi(pInOut, 2, 3, |GUI_SET_E_GUESS|)
    IncidentE = GetEiData.getPropertyValue('IncidentEnergy')

  LoadDetectorInfo(pInOut, input[0])

  #--sum all the workspaces, when the workspaces are not summed single input files are specified in this file and the final Python script is made of many copies of this file
  if len(input) > 1:
    for toAdd in input[ 1 : ] :
      toSum = common.LoadNexRaw(toAdd, conv.tempWS)          #save the memory by overwriting old workspaces
      LoadDetectorInfo(toSum, toAdd)
	  #the detector masking in pInOut will be preserved
      Plus(pInOut, toSum, pInOut)               #warning writing pInOut = pInOut + toSum  isn't be the same! That command would produce a new workspace because there is no way for the * operator to know that its output is also an input. The *= operator is much nicer
    mantid.deleteWorkspace(conv.tempWS)
  
  if |RM_BG| == 'yes':
    FlatBackground(pInOut, pInOut, |TOF_LOW|, |TOF_HIGH|, '', Mode='Mean')
  
  conv.NormaliseTo(|GUI_SET_NORM|, pInOut)
    
  ConvertUnits(pInOut, pInOut, 'DeltaE', 'Direct', IncidentE, 0)

  if |GUI_SET_BIN_BOUNDS| != '':
    Rebin(pInOut, pInOut, |GUI_SET_BIN_BOUNDS|)
  
  #--mask detectors that have failed tests run previously
  detIDs = []
  #-unless the string ''#+|MASK_WORKSPACE| below is replaced with a valid workspace name these lines do nothing
  DetectorMask = ''#+|MASK_WORKSPACE|
  if DetectorMask != '' :
    FDOL = FindDetectorsOutsideLimits(InputWorkspace=DetectorMask, OutputWorkspace=DetectorMask, HighThreshold=10, LowThreshold=-1, OutputFile='')
    detIDs = FDOL.getPropertyValue('BadDetectorIDs')
    MaskDetectors(Workspace=pInOut, DetectorList=detIDs)

  DetectorEfficiencyCor(pInOut, pInOut, IncidentE)
    
  mapFile = |GUI_SET_MAP_FILE|
  if mapFile != '':
    GroupDetectors( pInOut, pInOut, mapFile, KeepUngroupedSpectra=0)
  
  pInOut *= |GUI_SET_SCALING|	   #warning writing pInOut = pInOut * ...  isn't be the same! That command would produce a new workspace because there is no way for the * operator to know that its output is also an input. The *= operator is much nicer

 # if |GUI_SET_WBV| != '':
  conv.NormaliseToWhiteBeam(|GUI_SET_WBV|, pInOut, mapFile, |GUI_SET_WBV_REBIN|)

#  #####remove this line?###
#  ReplaceSpecialValues(nameInOut, nameInOut, 0, 0, 0)
  # output to a file in ASCII
  SaveSPE(pInOut, |GUI_SET_OUTPUT|)

except Exception:
  # delete the possibly part finished workspaces
  for workspace in mantid.getWorkspaceNames() :
    if (workspace == nameInOut) : mantid.deleteWorkspace(nameInOut)
  raise


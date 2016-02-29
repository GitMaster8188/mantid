import unittest
import platform
from mantid.simpleapi import *
from mantid.api import MatrixWorkspace, WorkspaceGroup

class IndirectNormSpectraTest(unittest.TestCase):

#----------------------------------Algorithm tests----------------------------------------

    def test_with_MatrixWorkspace_one_hist_positive(self):
        in_ws = self._create_MatrixWorkspace(1, 'test', True)
        out_ws = IndirectNormSpectra(InputWorkspace=in_ws)
        self._check_MatrixWorkspace_for_y_more_than_one(out_ws)

    def test_with_MatrixWorkspace_one_hist_negative(self):
        in_ws = self._create_MatrixWorkspace(1, 'test', False)
        out_ws = IndirectNormSpectra(InputWorkspace=in_ws)
        self._check_MatrixWorkspace_for_y_more_than_one(out_ws)

    def test_with_MatrixWorkspace_multi_hist_(self):
        in_ws = self._create_MatrixWorkspace(3, 'test', True)
        out_ws = IndirectNormSpectra(InputWorkspace=in_ws)
        self._check_MatrixWorkspace_for_y_more_than_one(out_ws)

#--------------------------------Validate results-----------------------------------------

    def _check_MatrixWorkspace_for_y_more_than_one(self, matrixWs):
        for i in range(matrixWs.getNumberHistograms()):
            self._check_spectrum_for_y_more_than_one(matrixWs.readY(i))

    def _check_spectrum_for_y_more_than_one(self, y_data):
        for i in range(len(y_data)):
            self.assertLessEqual(y_data[i], 1)

#--------------------------------Helper Functions-----------------------------------------
    def _create_MatrixWorkspace(self, nhists, out_name, positive):
        """
        Creates a basic Matrixworkspace
        """
        data = ""
        for i in range(nhists):
            if positive:
                data +='1,2,3,4,5'
            else:
                data +='-5,-4,-3,-2,-1'
            if i != (nhists - 1):
                data += ','
        CreateWorkspace(OutputWorkspace=out_name, DataX=data,
                        DataY=data, DataE=data, Nspec=nhists)
        return mtd[out_name]

if __name__=="__main__":
    unittest.main()

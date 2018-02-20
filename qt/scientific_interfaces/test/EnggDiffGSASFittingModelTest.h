#ifndef MANTIDQT_CUSTOMINTERFACES_ENGGDIFFGSASFITTINGMODELTEST_H_
#define MANTIDQT_CUSTOMINTERFACES_ENGGDIFFGSASFITTINGMODELTEST_H_

#include "../EnggDiffraction/EnggDiffGSASFittingModel.h"

#include "MantidAPI/AnalysisDataService.h"
#include "MantidAPI/FrameworkManager.h"
#include "MantidAPI/TableRow.h"
#include "MantidAPI/WorkspaceFactory.h"
#include "MantidTestHelpers/WorkspaceCreationHelper.h"

#include <cxxtest/TestSuite.h>

using namespace Mantid;
using namespace MantidQt::CustomInterfaces;

namespace { // Helpers

GSASIIRefineFitPeaksParameters createGSASIIRefineFitPeaksParameters(
    const API::MatrixWorkspace_sptr &inputWS, const RunLabel &runLabel,
    const GSASRefinementMethod &refinementMethod) {
  return GSASIIRefineFitPeaksParameters(
      inputWS, runLabel, refinementMethod, "", std::vector<std::string>({}), "",
      "", boost::none, boost::none, boost::none, boost::none, false, false);
}

template <size_t numColumns, size_t numRows>
API::ITableWorkspace_sptr createDummyTable(
    const std::array<std::string, numColumns> &columnHeadings,
    const std::array<std::array<double, numColumns>, numRows> tableContents) {
  auto table = API::WorkspaceFactory::Instance().createTable();
  for (const auto &header : columnHeadings) {
    table->addColumn("double", header);
  }
  for (const auto &row : tableContents) {
    API::TableRow newRow = table->appendRow();
    for (const auto value : row) {
      newRow << value;
    }
  }
  return table;
}

// Helper class with some protected methods exposed
class TestEnggDiffGSASFittingModel : public EnggDiffGSASFittingModel {
public:
  void addLatticeParamTable(const RunLabel &runLabel,
                            API::ITableWorkspace_sptr table);

  void addRwpValue(const RunLabel &runLabel, const double rwp);

private:
  inline double
  doGSASRefinementAlgorithm(const std::string &fittedPeaksWSName,
                            const std::string &latticeParamsWSName,
                            const GSASIIRefineFitPeaksParameters &params,
                            const std::string &refinementMethod) override;
};

inline void TestEnggDiffGSASFittingModel::addLatticeParamTable(
    const RunLabel &runLabel, API::ITableWorkspace_sptr table) {
  addLatticeParams(runLabel, table);
}

inline void TestEnggDiffGSASFittingModel::addRwpValue(const RunLabel &runLabel,
                                                      const double rwp) {
  addRwp(runLabel, rwp);
}

inline double TestEnggDiffGSASFittingModel::doGSASRefinementAlgorithm(
    const std::string &fittedPeaksWSName,
    const std::string &latticeParamsWSName,
    const GSASIIRefineFitPeaksParameters &params,
    const std::string &refinementMethod) {
  // Mock method - just create some dummy output and ignore all the parameters
  UNUSED_ARG(params);
  UNUSED_ARG(refinementMethod);

  const static std::array<std::string, 3> columnHeadings = {{"a", "b", "c"}};
  const static std::array<std::array<double, 3>, 1> targetTableValues = {
      {{{1, 2, 3}}}};
  const auto latticeParams =
      createDummyTable(columnHeadings, targetTableValues);

  API::AnalysisDataServiceImpl &ADS = API::AnalysisDataService::Instance();
  ADS.add(latticeParamsWSName, latticeParams);

  API::MatrixWorkspace_sptr ws =
      WorkspaceCreationHelper::create2DWorkspaceBinned(4, 4, 0.5);
  ADS.add(fittedPeaksWSName, ws);

  return 75;
}

} // Anonymous namespace

class EnggDiffGSASFittingModelTest : public CxxTest::TestSuite {
public:
  // This pair of boilerplate methods prevent the suite being created statically
  // This means the constructor isn't called when running other tests
  static EnggDiffGSASFittingModelTest *createSuite() {
    return new EnggDiffGSASFittingModelTest();
  }
  static void destroySuite(EnggDiffGSASFittingModelTest *suite) {
    delete suite;
  }

  EnggDiffGSASFittingModelTest() { API::FrameworkManager::Instance(); }

  void test_validLoadRun() {
    const static std::string inputFilename = "ENGINX_277208_focused_bank_2.nxs";
    TestEnggDiffGSASFittingModel model;

    API::MatrixWorkspace_sptr ws;
    TS_ASSERT_THROWS_NOTHING(ws = model.loadFocusedRun(inputFilename));
    TS_ASSERT(ws);
  }

  void test_invalidLoadRun() {
    const static std::string inputFilename = "ENGINX_277209_focused_bank_2.nxs";
    TestEnggDiffGSASFittingModel model;

    API::MatrixWorkspace_sptr ws;
    TS_ASSERT_THROWS_ANYTHING(ws = model.loadFocusedRun(inputFilename));
    TS_ASSERT(!ws);
  }

  void test_getRwp() {
    TestEnggDiffGSASFittingModel model;

    const RunLabel valid(123, 1);
    const double rwp = 75.5;
    model.addRwpValue(valid, rwp);

    auto retrievedRwp = boost::make_optional<double>(false, double());
    TS_ASSERT_THROWS_NOTHING(retrievedRwp = model.getRwp(valid));
    TS_ASSERT(retrievedRwp);
    TS_ASSERT_EQUALS(rwp, *retrievedRwp);

    const RunLabel invalid(456, 2);
    TS_ASSERT_THROWS_NOTHING(retrievedRwp = model.getRwp(invalid));
    TS_ASSERT_EQUALS(retrievedRwp, boost::none);
  }

  void test_getLatticeParams() {
    const std::array<std::string, 3> columnHeadings = {{"a", "b", "c"}};
    const std::array<std::array<double, 3>, 1> targetTableValues = {
        {{{1, 2, 3}}}};
    const auto table = createDummyTable(columnHeadings, targetTableValues);

    TestEnggDiffGSASFittingModel model;

    const RunLabel valid(123, 1);
    TS_ASSERT_THROWS_NOTHING(model.addLatticeParamTable(valid, table));

    // auto retrievedTable = model.getLatticeParams(123, 1);
    boost::optional<API::ITableWorkspace_sptr> retrievedTable;
    TS_ASSERT_THROWS_NOTHING(retrievedTable = model.getLatticeParams(valid));
    TS_ASSERT(retrievedTable);

    API::TableRow row = (*retrievedTable)->getRow(0);
    const double expectedA = 1;
    const double expectedB = 2;
    const double expectedC = 3;
    auto a = expectedA + 1;
    auto b = expectedB + 1;
    auto c = expectedC + 1;

    TS_ASSERT_THROWS_NOTHING(row >> a >> b >> c);
    TS_ASSERT_EQUALS(a, expectedA);
    TS_ASSERT_EQUALS(b, expectedB);
    TS_ASSERT_EQUALS(c, expectedC);

    const RunLabel invalid(456, 2);
    TS_ASSERT_THROWS_NOTHING(retrievedTable = model.getLatticeParams(invalid));
    TS_ASSERT_EQUALS(retrievedTable, boost::none);
  }

  void test_pawleyRefinement() {
    // Note: due to the reliance on GSAS-II, this cannot test that the algorithm
    // is used properly. It tests that, given that the algorithm is used
    // properly, results are added to the appropriate maps in the model
    TestEnggDiffGSASFittingModel model;
    const RunLabel runLabel(123, 1);

    API::MatrixWorkspace_sptr inputWS =
        API::WorkspaceFactory::Instance().create("Workspace2D", 1, 10, 10);

    API::MatrixWorkspace_sptr fittedPeaks;
    TS_ASSERT_THROWS_NOTHING(
        fittedPeaks =
            model.doPawleyRefinement(createGSASIIRefineFitPeaksParameters(
                inputWS, runLabel, GSASRefinementMethod::PAWLEY)));
    TS_ASSERT(fittedPeaks);

    const auto rwp = model.getRwp(runLabel);
    TS_ASSERT(rwp);

    const auto latticeParams = model.getLatticeParams(runLabel);
    TS_ASSERT(latticeParams);

    API::AnalysisDataService::Instance().clear();
  }

  void test_RietveldRefinement() {
    // Note: due to the reliance on GSAS-II, this cannot test that the algorithm
    // is used properly. It tests that, given that the algorithm is used
    // properly, results are added to the appropriate maps in the model
    TestEnggDiffGSASFittingModel model;
    const RunLabel runLabel(123, 1);

    API::MatrixWorkspace_sptr inputWS =
        API::WorkspaceFactory::Instance().create("Workspace2D", 1, 10, 10);

    API::MatrixWorkspace_sptr fittedPeaks;
    TS_ASSERT_THROWS_NOTHING(
        fittedPeaks =
            model.doRietveldRefinement(createGSASIIRefineFitPeaksParameters(
                inputWS, runLabel, GSASRefinementMethod::RIETVELD)));
    TS_ASSERT(fittedPeaks);

    const auto rwp = model.getRwp(runLabel);
    TS_ASSERT(rwp);

    const auto latticeParams = model.getLatticeParams(runLabel);
    TS_ASSERT(latticeParams);

    API::AnalysisDataService::Instance().clear();
  }
};

#endif // MANTIDQT_CUSTOMINTERFACES_ENGGDIFFGSASFITTINGMODELTEST_H_

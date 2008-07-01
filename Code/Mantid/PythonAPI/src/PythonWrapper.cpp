#include <vector>

// Boost Includes ==============================================================
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
#include "boost/cstdint.hpp"

// Includes ====================================================================
#include "MantidPythonAPI/PythonInterface.h"
#include "MantidPythonAPI/FrameworkManager.h"
#include "MantidAPI/IAlgorithm.h"
#include "MantidAPI/Workspace.h"

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================

typedef std::vector< std::string > string_vec;
typedef std::vector< double > double_vec;

struct Mantid_API_IAlgorithm_Wrapper: Mantid::API::IAlgorithm
{
    Mantid_API_IAlgorithm_Wrapper(PyObject* py_self_, const Mantid::API::IAlgorithm& p0):
        Mantid::API::IAlgorithm(p0), py_self(py_self_) {}

    Mantid_API_IAlgorithm_Wrapper(PyObject* py_self_):
        Mantid::API::IAlgorithm(), py_self(py_self_) {}

    void initialize() {
        call_method< void >(py_self, "initialize");
    }

    bool execute() {
        return call_method< bool >(py_self, "execute");
    }

    bool isInitialized() const {
        return call_method< bool >(py_self, "isInitialized");
    }

    bool isExecuted() const {
        return call_method< bool >(py_self, "isExecuted");
    }

    void setPropertyValue(int p0, int p1) {
        call_method< void >(py_self, "setPropertyValue", p0, p1);
    }

    bool getPropertyValue(int p0) const {
        return call_method< bool >(py_self, "getPropertyValue", p0);
    }

    PyObject* py_self;
};

struct Mantid_API_Workspace_Wrapper: Mantid::API::Workspace
{
    const std::string id() const {
        return call_method< const std::string >(py_self, "id");
    }

    void init(const int& p0, const int& p1, const int& p2) {
        call_method< void >(py_self, "init", p0, p1, p2);
    }

    long int getMemorySize() const {
        return call_method< long int >(py_self, "getMemorySize");
    }

    long int default_getMemorySize() const {
        return Mantid::API::Workspace::getMemorySize();
    }

    int size() const {
        return call_method< int >(py_self, "size");
    }

    int blocksize() const {
        return call_method< int >(py_self, "blocksize");
    }

    int spectraNo(const int p0) const {
        return call_method< int >(py_self, "spectraNo", p0);
    }

    int& spectraNo(const int p0) {
        return call_method< int& >(py_self, "spectraNo", p0);
    }
    
    const std::vector<double,std::allocator<double> >& getX(const int p0) const {
        return call_method< const std::vector<double,std::allocator<double> >& >(py_self, "getX", p0);
    }

    const std::vector<double,std::allocator<double> >& getY(const int p0) const {
        return call_method< const std::vector<double,std::allocator<double> >& >(py_self, "getY", p0);
    }

    const std::vector<double,std::allocator<double> >& getE(const int p0) const {
        return call_method< const std::vector<double,std::allocator<double> >& >(py_self, "getE", p0);
    }

    PyObject* py_self;
};

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Mantid_PythonAPI_FrameworkManager_createAlgorithm_overloads_1_2, createAlgorithm, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Mantid_PythonAPI_FrameworkManager_createAlgorithm_overloads_2_3, createAlgorithm, 2, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Mantid_PythonAPI_FrameworkManager_execute_overloads_2_3, execute, 2, 3)

#if _WIN32
BOOST_PYTHON_MODULE(MantidPythonAPI)
#else
BOOST_PYTHON_MODULE(libMantidPythonAPI)
#endif
{	
	//Vectors
	class_< string_vec >( "StringVec" )
	.def( vector_indexing_suite< string_vec >() )
        ;
	
	class_< double_vec >( "DoubleVec" )
	.def( vector_indexing_suite< double_vec >() )
	;
	
	register_ptr_to_python< boost::shared_ptr<Mantid::API::Workspace> >();
	register_ptr_to_python< boost::shared_ptr<Mantid::Kernel::Unit> >();
	
	//Namespace Functions
        def("LoadIsisRawFile", &Mantid::PythonAPI::LoadIsisRawFile);
	def("GetAlgorithmNames", &Mantid::PythonAPI::GetAlgorithmNames);
	def("GetWorkspaceNames", &Mantid::PythonAPI::GetWorkspaceNames);
	
	//IAlgorithm Class
	class_< Mantid::API::IAlgorithm, boost::noncopyable, Mantid_API_IAlgorithm_Wrapper >("IAlgorithm", no_init)
        .def("initialize", pure_virtual(&Mantid::API::IAlgorithm::initialize))
        .def("execute", pure_virtual(&Mantid::API::IAlgorithm::execute))
        .def("isInitialized", pure_virtual(&Mantid::API::IAlgorithm::isInitialized))
        .def("isExecuted", pure_virtual(&Mantid::API::IAlgorithm::isExecuted))
        .def("setPropertyValue", pure_virtual(&Mantid::API::IAlgorithm::setPropertyValue))
        .def("getPropertyValue", pure_virtual(&Mantid::API::IAlgorithm::getPropertyValue))
	;
	
	//Workspace Class
	class_< Mantid::API::Workspace, boost::noncopyable, Mantid_API_Workspace_Wrapper >("Workspace", no_init)
        .def("id", pure_virtual(&Mantid::API::Workspace::id))
        .def("initialize", &Mantid::API::Workspace::initialize)
        .def("getMemorySize", &Mantid::API::Workspace::getMemorySize, &Mantid_API_Workspace_Wrapper::default_getMemorySize)
        .def("size", pure_virtual(&Mantid::API::Workspace::size))
        .def("blocksize", pure_virtual(&Mantid::API::Workspace::blocksize))
        .def("setTitle", &Mantid::API::Workspace::setTitle)
        .def("setComment", &Mantid::API::Workspace::setComment)
        .def("getComment", &Mantid::API::Workspace::getComment, return_value_policy< copy_const_reference >())
        .def("getTitle", &Mantid::API::Workspace::getTitle, return_value_policy< copy_const_reference >())
        .def("isDistribution", (const bool& (Mantid::API::Workspace::*)() const)&Mantid::API::Workspace::isDistribution, return_value_policy< copy_const_reference >())
        .def("getX", pure_virtual((const std::vector<double,std::allocator<double> >* (Mantid::API::Workspace::*)(const int) const)&Mantid::API::Workspace::getX), return_value_policy< manage_new_object >())
        .def("getY", pure_virtual((const std::vector<double,std::allocator<double> >* (Mantid::API::Workspace::*)(const int) const)&Mantid::API::Workspace::getY), return_value_policy< manage_new_object >())
        .def("getE", pure_virtual((const std::vector<double,std::allocator<double> >* (Mantid::API::Workspace::*)(const int) const)&Mantid::API::Workspace::getE), return_value_policy< manage_new_object >())
    ;

	//Framework Class
	class_< Mantid::PythonAPI::FrameworkManager, boost::noncopyable >("FrameworkManager", init<  >())
        .def("clear", &Mantid::PythonAPI::FrameworkManager::clear)
        .def("createAlgorithm", (Mantid::API::IAlgorithm* (Mantid::PythonAPI::FrameworkManager::*)(const std::string&, const int&) )&Mantid::PythonAPI::FrameworkManager::createAlgorithm, return_value_policy< manage_new_object >(), Mantid_PythonAPI_FrameworkManager_createAlgorithm_overloads_1_2())
        .def("createAlgorithm", (Mantid::API::IAlgorithm* (Mantid::PythonAPI::FrameworkManager::*)(const std::string&, const std::string&, const int&) )&Mantid::PythonAPI::FrameworkManager::createAlgorithm, return_value_policy< manage_new_object >(), Mantid_PythonAPI_FrameworkManager_createAlgorithm_overloads_2_3())
        .def("execute", &Mantid::PythonAPI::FrameworkManager::execute, return_value_policy< manage_new_object >(), Mantid_PythonAPI_FrameworkManager_execute_overloads_2_3())
        .def("getWorkspace", &Mantid::PythonAPI::FrameworkManager::getWorkspace, return_value_policy< manage_new_object >())
        .def("deleteWorkspace", &Mantid::PythonAPI::FrameworkManager::deleteWorkspace)
    ;

}


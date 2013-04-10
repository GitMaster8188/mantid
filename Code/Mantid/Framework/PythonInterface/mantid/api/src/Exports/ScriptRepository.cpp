#include "MantidAPI/ScriptRepository.h"
#include "MantidPythonInterface/kernel/PythonObjectInstantiator.h"
#include "MantidPythonInterface/kernel/SharedPtrToPythonMacro.h"

//#include "MantidPythonInterface/api/PythonAlgorithm/AlgorithmWrapper.h"

#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <boost/python/tuple.hpp>
#include <boost/python/docstring_options.hpp>

// Python frameobject. This is under the boost includes so that boost will have done the
// include of Python.h which it ensures is done correctly
#include <frameobject.h>

using Mantid::API::ScriptRepository; 
using namespace Mantid::API;
using namespace boost::python;
using boost::python::tuple;
namespace
{
  /** @cond */

  //------------------------------------------------------------------------------------------------------
  /**
   * A Python friendly version that returns the registered functions as a list.
   * @param self :: Enables it to be called as a member function on the FunctionFactory class
   */
  PyObject * getListFiles(ScriptRepository & self)
  {
    std::vector<std::string> files = self.listFiles();

    PyObject *registered = PyList_New(0);
    for (auto file = files.begin(); file != files.end(); ++file)
    {
      PyObject *value = PyString_FromString(file->c_str());
      if (PyList_Append(registered, value))
        throw std::runtime_error("Failed to insert value into PyList");
    }

    return registered;
    }

  tuple getInfo(ScriptRepository & self, const std::string path){
    ScriptInfo info = self.info(path);
    return   boost::python::make_tuple<std::string>(info.author, info.description, info.pub_date.toSimpleString() );
  }

  PyObject * getStatus(ScriptRepository & self, const std::string path){
    SCRIPTSTATUS st = self.fileStatus(path); 
    PyObject * value; 
    switch(st){
    case BOTH_UNCHANGED:
      value = PyString_FromString("BOTH_UNCHANGED"); 
      break;
    case REMOTE_ONLY:
      value = PyString_FromString("REMOTE_ONLY");
      break;
    case LOCAL_ONLY:
      value = PyString_FromString("LOCAL_ONLY"); 
      break; 
    case REMOTE_CHANGED:
      value = PyString_FromString("REMOTE_CHANGED");
      break;
    case LOCAL_CHANGED:
      value = PyString_FromString("LOCAL_CHANGED");
      break;
    case BOTH_CHANGED:
      value = PyString_FromString("BOTH_CHANGED");
    break;
    default:
      value = PyString_FromString("BOTH_UNCHANGED"); 
      break;
    }
    return value;
  }

  /** @endcond */
}

void export_ScriptRepository()
{

  REGISTER_SHARED_PTR_TO_PYTHON(ScriptRepository);
  //  class_<ScriptRepository, boost::noncopyable>("ScriptRepository", "Base-class for ScriptRepository", no_init);

  // reset the option to 
 docstring_options local_docstring_options(true, true, false);

const char * repo_desc = 
"Manage the interaction between the users and the Script folder (mantid subproject). \n\
\n\
Inside the mantid repository (https://github.com/mantidproject) there is also a subproject \n\
called scripts (https://github.com/mantidproject/scripts), created to allow users to share \n\
their scripts, as well as to allow Mantid Team to distribute to the Mantid community \n\
scripts for analysis and also to enhance the quality of the scripts used for the sake of \n\
data analysis. \n\
\n\
The ScriptRepository aims to provide a simple way to interact with that repository in \n\
order to promote its usage. In order to enhance the usage, it is necessary:\n\
  \n\
 - List all scripts available at the repository\n\
 - Download selected scripts. \n\
 - Check for updates\n\
 - Allow to publish users scripts/folders. \n\
\n\
Basically, you will need to install the repository through ::install(local_path). \n\
After, you will be able to ::listFiles inside your repository to check the files that are \n\
available, eventually, you may want to check the information of a single entry \n\
::fileInfo(path). You may also be interested to know if there is a new version available, \n\
or if the file has been modified since last downloaded (::fileStatus(path)). You may want \n\
to download scripts through ::download(path), or check for updates through ::update(). \n\
\n\
'''NOTE:''' Upload is not implemented yet.\n";

const char * list_files_desc = 
"Return an array with all the entries inside the repository. \n\
\n\
Folder os files, locally or remotely, all will be listed together through the listFiles. \n\
The listFiles has another function, which is related to update the internal cache about \n\
the status and information of the files. So, local changes or remote changes will only be \n\
available to fileStatus of fileInfo after listFiles.\n\
\n\
:return : list of entries inside the repository.\n";

const char * file_info_desc = 
"Return general information from the entries inside ScriptRepository. \n\
\n\
The author, description and publication date are available through this method. \n\
\n\
:param path: Path to the entry.\n\
:return : Tuple with (author, description, last publication date)\n";

const char * file_status_desc = 
"Return the status of a given entry.\n\
\n\
The following status are applied to the entries:\n\
  - REMOTE_ONLY: The file is only at the central repository\n\
  - LOCAL_ONLY: The file is only in your file system\n\
  - BOTH_UNCHAGED: The file is in your file system and remotely, and are iqual.\n\
  - REMOTE_CHANGED: A new version is available for this file.\n\
  - LOCAL_CHANGED: You have edited the file\n\
  - BOTH_CHANGED: There is a new version and you have changed as well\n\
\n\
'''NOTE:''' ScriptRepository recognizes changes locally and remotely only through \n\
listFiles method.\n\
:param path: The path for the entry.\n\
:return : String with the status of the entry.\n";

const char * download_desc =
"Download from repository into your local file system.\n\
\n\
You may give a file or folder. If the later is given, ScriptRepository will \n\
download all the files inside that folder from the remote repository to you.\n\
:param path: Path for the entry do download";

const char * update_desc = 
"Check for updates at the remote repository.\n\
\n\
New versions of the files may be available, and the update method will check the \n\
remote repository to see if there is anything new. It will not download new versions \n\
of the available files unless you ask to do so. You should do this often to check if \n\
there is a new script to solve your problem ;)";


const char * install_desc =
"Install the ScriptRepository in your local file system\n\
\n\
The installation of the ScriptRepository is very simple. You must only provide a path, \n\
existing or new folder, where the ScriptRepository will put the database it requires to \n\
run itself. The installation requires network connection, to connect to the central \n\
repository but usually takes very few moments to be installed. After installing, all the \n\
others methods will be available.\n\
: param path: An existing or path to a new folder to be created, where the \n\
ScriptRepository will install itself.";

  ///@todo beter description
  class_<ScriptRepository,boost::noncopyable>("ScriptRepository",  repo_desc, no_init)
    .def("install",&ScriptRepository::install, install_desc)
    .def("listFiles",&getListFiles, list_files_desc)
    .def("fileInfo",&getInfo,file_info_desc)
    .def("fileStatus",&getStatus,file_status_desc)
    .def("download",&ScriptRepository::download,download_desc)
    //.def("upload",&ScriptRepository::upload, "")
    .def("update",&ScriptRepository::check4Update,update_desc);  
}

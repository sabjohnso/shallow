#include <shallow/app/RuntimeConfig.hpp>

//
// ... Standard header files
//
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <optional>

//
// ... External header files
//
#include <boost/program_options.hpp>

//
// ... Shallow header files
//
#include <shallow/config.hpp>
#include <shallow/app/HelpException.hpp>
#include <shallow/app/VersionException.hpp>

namespace po = boost::program_options;
using nlohmann::json;
using std::back_inserter;
using std::copy_n;
using std::string;
using std::to_string;

namespace Shallow
{


  namespace // anonymous
  {
    string
    version(){
      using Version = Config::Info::Version;
      return
        to_string(Version::major) + "." +
        to_string(Version::minor);
    }



    void
    process_commandline(po::options_description& desc, int argc, const char* const * argv){
      po::variables_map vm;
      po::store(po::parse_command_line(argc, argv, desc), vm);
      po::notify(vm);

      if(vm.count("help"))
      {
        std::ostringstream oss;
        oss << desc;
        throw HelpException(oss.str());
      }
      else if (vm.count("version"))
      {
        throw VersionException(version());
      }
    }
  } // end of anonymous namespace

  RuntimeConfig::RuntimeConfig(int argc, const char* const * argv){
    po::options_description desc("Shallow options");
    desc.add_options()
      ("help,h", "produce this help message and exit\n")

      ("version", "produce the version and exit\n")

      ("input-file,f", po::value<string>(&input_path)->default_value(""),
       "path to the shallow input file\n")

      ("distributed,d", po::value<bool>(&multiprocess)->default_value(false),
       "Multiprocess/distributed execution using MPI\n")

      ("thread-limit,t", po::value<integer>(&thread_limit)->default_value(0),
       "Maximum number of threads perprocess\n"
       "When 0 or less, the number of threads is not limited "
       "and execution will consume all available compute "
       "resources.\n");

    process_commandline(desc, argc, argv);

  }

  bool
  RuntimeConfig::is_multiprocess() const {
    return multiprocess;
  }

  integer
  RuntimeConfig::maxthreads() const { return thread_limit; }


  std::optional<std::string>
  RuntimeConfig::input() const {
    return input_path == ""
      ? std::optional<std::string>(std::nullopt)
      : std::optional<std::string>(input_path);
  }

} // end of namespace Shallow

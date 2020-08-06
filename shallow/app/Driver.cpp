#include <shallow/app/Driver.hpp>

//
// ... External header files
//
#include <mpi.h>

//
// ... shallow header files
//
#include <shallow/app/RuntimeConfig.hpp>

namespace Shallow
{
  namespace // anonymous
  {


  } // end of anonymous namespace



  Driver::Driver(int argc, char** argv)
    : exit_code(0)
    , config(argc, argv) {
    if(config.is_multiprocess()){
      multiprocess_execution(argc, argv);
    } else {
      single_process_execution();
    }
  }

  void
  Driver::multiprocess_execution(int argc, char** argv){
    MPI_Init(&argc, &argv);

    MPI_Finalize();
  }

  void
  Driver::single_process_execution(){
  }



  Driver::operator int() const { return exit_code; }

} // end of namespace Shallow

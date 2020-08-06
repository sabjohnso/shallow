
//
// ... Shallow header files
//
#include <shallow/app/Driver.hpp>
#include <shallow/app/ExceptionHandler.hpp>

int
main(int argc, char** argv)
{
  try{
    return Shallow::Driver(argc, argv);
  } catch (...){
    return Shallow::ExceptionHandler();
  }
}

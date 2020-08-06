#include <shallow/app/ExceptionHandler.hpp>

//
// ... Standard header files
//
#include <iostream>
#include <exception>

//
// ... Shallow header files
//
#include <shallow/app/HelpException.hpp>
#include <shallow/app/VersionException.hpp>


namespace Shallow
{

  ExceptionHandler::ExceptionHandler()
    : exit_code(-1)
  {
    try{
      std::rethrow_exception(std::current_exception());

    } catch(HelpException const& e){
      std::cout << e.what() << std::endl;
      exit_code = 0;

    } catch(VersionException const& e){
      std::cout << e.what() << std::endl;
      exit_code = 0;

    } catch(std::exception& e){
      std::cerr << "\n\nAn unexpected error was encounterd:\n"
                << e.what()
                << std::endl;
    }
  }

  ExceptionHandler::operator int() const {
    return exit_code;
  }
} // end of namespace Shallow

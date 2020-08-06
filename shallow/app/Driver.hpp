#pragma once

//
// ... Shallow header files
//
#include <shallow/app/RuntimeConfig.hpp>

namespace Shallow
{

  class Driver
  {
  public:
    /**
     * @brief Primary execution driver for the shallow appliction
     */
    Driver(int argc, char** argv);
    operator int () const;
  private:

    /**
     * @brief Multiprocess execution control
     */
    void
    multiprocess_execution(int argc, char** argv);

    /**
     * @brief Single process execution control
     */
    void
    single_process_execution();

    int exit_code;
    RuntimeConfig config;
  };// end of class Driver

} // end of namespace Shallow

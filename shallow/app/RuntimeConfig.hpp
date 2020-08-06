#pragma once

//
// ... standard header files
//
#include <string>
#include <optional>

//
// ... External header files
//
#include <nlohmann/json.hpp>

//
// ... Shallow header files
//
#include <shallow/shallow.hpp>

namespace Shallow
{

  /**
   * @brief A class describing the runtime configuration for the
   * shallow application.
   *
   * @details This class represents execution control aspects of
   * the shallow application, which is distinct from the case definitions
   * which are obtained though input files.
   */
  class RuntimeConfig
  {
  public:
    RuntimeConfig(int argc, const char* const *argv);

    /**
     * @brief Return true if the shallow application is to be
     * run in a multiprocess manner using MPI.
     */
    bool
    is_multiprocess() const;

    /**
     * @brief Return the maximum number of threads (per process)
     * for running the shallow application.
     *
     * @details This configuration control is intended to limit
     * the number of threads the shallow application uses when being executed
     * on a machine that is being used simultaneously for other tasks.  If the
     * value is 0 or less, the shallow application will use all available
     * resources.
     */
    integer
    maxthreads() const;

    /**
     * @brief Return the optional input path.
     *
     * @details When the input path is not specified, the shallow application
     * will read the input from the standard input stream.
     */
    std::optional<std::string>
    input() const;

  private:
    bool multiprocess;
    integer thread_limit;
    std::string input_path;
  }; // end of class RuntimeConfig

} // end of namespace Shallow

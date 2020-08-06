#pragma once

#include <stdexcept>

namespace Shallow
{
  class VersionException : public std::runtime_error
  {
  public:
    using std::runtime_error::runtime_error;
  }; // end of class VersionException

} // end of namespace Shallow

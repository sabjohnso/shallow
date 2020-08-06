#pragma once

#include <stdexcept>

namespace Shallow
{

  class HelpException : public std::runtime_error
  {
  public:
    using std::runtime_error::runtime_error;
  }; // end of class HelpException


} // end of namespace Shallow

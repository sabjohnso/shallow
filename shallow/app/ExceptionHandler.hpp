#pragma once

namespace Shallow
{

  class ExceptionHandler
  {
  public:
    ExceptionHandler();
    operator int() const;
  private:
    int exit_code;
  }; // end of class ExceptionHandler

} // end of namespace Shallow

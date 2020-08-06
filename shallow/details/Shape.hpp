#pragma once

//
// ... Shallow header files
//
#include <shallow/details/import.hpp>

namespace Shallow::Details
{
  class Shape : public Vec2<integer>
  {
  public:
    using Vec2<integer>::Vec2;
  }; // end of class Shape


} // end of namespace Shallow::Details

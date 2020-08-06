#pragma once

//
// ... Shallow header files
//
#include <shallow/details/import.hpp>


namespace Shallow::Details
{
  template<typename T>
  class Vec2
  {
  public:
    using value_type = T;

    Vec2() = delete;

    constexpr
    Vec2(value_type x, value_type y) : x(x), y(y) {}

    constexpr value_type
    operator ()(integer index) const {
      return index == 0 ? x : y;
    }

    const value_type x;
    const value_type y;
  }; // end of struct Vec2

} // end of namespace Shallow::Details

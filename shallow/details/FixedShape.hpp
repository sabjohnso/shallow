#pragma once

//
// ... Shallow header files
//
#include <shallow/details/Shape.hpp>

namespace Shallow::Details
{
  template<integer M, integer N>
  class FixedShape
  {
  public:

    static constexpr Shape shape{M,N};

    constexpr
    operator Shape() const { return shape; }

  }; // end of class FixedShape
} // end of namespace Shallow::Details

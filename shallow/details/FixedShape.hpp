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

    template<integer M2, integer N2>
    friend constexpr auto
    operator +(FixedShape, FixedShape<M2,N2>){
      return FixedShape<M+M2,N+N2>{};
    }

  }; // end of class FixedShape
} // end of namespace Shallow::Details

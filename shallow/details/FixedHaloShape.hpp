#pragma once

//
// ... Shallow header files
//
#include <shallow/details/HaloShape.hpp>
#include <shallow/details/FixedShape.hpp>

namespace Shallow::Details
{
  template<integer M, integer N>
  class FixedHaloShape : public FixedShape<M,N>
  {
  public:
    static constexpr HaloShape shape{M,N};

    constexpr
    operator HaloShape() const { return shape; }

  }; // end of class FixedHaloShape
} // end of namespace Shallow::Details

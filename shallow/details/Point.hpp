#pragma once

//
// ... Shallow header files
//
#include <shallow/details/Vec2.hpp>


namespace Shallow::Details
{
  template<typename T>
  class Point : public Vec2<T>, EuclideanArithmetic<Point<T>>
  {
  public:
    using Vec2<T>::Vec2;
  }; // end of class Point
} // end of namespace Shallow::Details

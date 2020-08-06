#pragma once

//
// ... Shalow header files
//
#include <shallow/details/Point.hpp>

namespace Shallow::Details
{
  template<typename T>
  class BoundingBox
  {

  public:

    BoundingBox() = delete;

    BoundingBox(Point<T> lower, Point<T> upper)
      : lower{lower}
      , upper{upper}
    {}

    const Point<T> lower;
    const Point<T> upper;
  }; // end of class BoundingBox

  template<typename T>
  BoundingBox(Point<T> lower, Point<T> upper) -> BoundingBox<T>;

} // end of namespace Shallow::Details

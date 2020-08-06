#pragma once
//
// ... Shallow header files
//
#include <shallow/details/import.hpp>
#include <shallow/details/Vec2.hpp>
#include <shallow/details/Euclidean.hpp>

namespace Shallow::Details
{

  /**
   * @brief A class representing the origin of a grid
   * in two-dimensional space
   */
  template<typename T>
  class Origin
    : public Vec2<T>
    , public EuclideanArithmetic<Origin<T>>
  {
  public:
    using Vec2<T>::Vec2;
  }; // end of class Origin

  template<typename T>
  Origin(T x, T y) -> Origin<T>;

} // end of namespace Shallow::Details

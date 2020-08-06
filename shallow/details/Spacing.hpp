#pragma once
//
// ... Shallow header files
//
#include <shallow/details/import.hpp>

namespace Shallow::Details
{

  /**
   * @brief A class representing the spacing of a
   * grid in two-dimensional space
   */
  template<typename T>
  class Spacing
    : public Vec2<T>
    , public EuclideanArithmetic<Spacing<T>>
  {
  public:
    using Vec2<T>::Vec2;
  }; // end of class Spacing

  template<typename T>
  Spacing(T x, T y) -> Spacing<T>;


} // end of namespace Shallow::Details

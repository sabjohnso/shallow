#pragma once

//
// ... Shallow header files
//
#include <shallow/details/import.hpp>
#include <shallow/details/Origin.hpp>
#include <shallow/details/Spacing.hpp>


namespace Shallow::Details
{

  /**
   * @brief A class representing the a root grid
   *
   * @details Here, a root grid is an orthogonal grid
   * with uniform mesh spacing in two-dimensional space
   * and infinite extents in both directions.
   */
  template<typename T>
  class RootGrid
  {
  public:
    using value_type = T;
    using origin_type = Origin<value_type>;
    using spacing_type = Spacing<value_type>;

    RootGrid() = delete;

    constexpr
    RootGrid(origin_type origin_input , spacing_type spacing_input)
      : origin(move(origin_input))
      , spacing(move(spacing_input))
    {}

    const origin_type origin;
    const spacing_type spacing;

  }; // end of struct RootGrid

} // end of namespace Shallow::Details

#pragma once

//
// ... RootGrid header files
//
#include <shallow/details/RootGrid.hpp>
#include <shallow/details/Offset.hpp>
#include <shallow/details/FixedShape.hpp>
#include <shallow/details/FixedHaloShape.hpp>
#include <shallow/details/Point.hpp>
#include <shallow/details/BoundingBox.hpp>

namespace Shallow::Details
{

  template<typename T, integer Nx = 64, integer Ny = 64, integer NHx = 1, integer NHy = 1 >
  class Subgrid
  {

  public:
    using value_type = T;
    using root_type = RootGrid<value_type>;

    constexpr static FixedShape<Nx,Ny> shape{};
    constexpr static FixedHaloShape<NHx, NHy> halo_shape{};

    Subgrid() = delete;

    constexpr
    Subgrid(root_type root_input, Offset offset_input, integer level_input)
      : root(move(root_input))
      , offset(move(offset_input))
      , level(level_input)
    {}

    constexpr auto
    spacing(){ return root.spacing / exp2(level); }

    constexpr auto
    spacing(integer index){ return root.spacing(index) / exp2(level); }

    constexpr auto
    x(integer index){ return (offset.x + index) * spacing(0); }

    constexpr auto
    y(integer index){ return (offset.y + index) * spacing(1); }

    constexpr auto
    lower_bound() const {
      return Point{offset.x * spacing(0), offset.y * spacing(1)};
    }

    constexpr auto
    upper_bound() const {
      return Point{(offset.x + shape.x) * spacing(0), (offset.y + shape.y) * spacing(1)};
    }

    constexpr auto
    bounding_box(){ return BoundingBox{lower_bound(), upper_bound()}; }

    const root_type root;
    const Offset offset;
    const integer level;

  }; // end of class Subgrid

  template<typename T>
  Subgrid(RootGrid<T> root, Offset offset, integer level) -> Subgrid<T>;

} // end of namespace Shallow::Details

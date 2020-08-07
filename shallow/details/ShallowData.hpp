#pragma once

//
// ... Shallow header files
//
#include <shallow/details/import.hpp>
#include <shallow/details/Subgrid.hpp>

namespace Shallow::Details
{
  enum class Field{ h, u, v };
  template<typename T, typename Grid = Subgrid<T> >
  class ShallowData
  {
  public:
    static constexpr integer nx = Grid::shape.shape.x;
    static constexpr integer ny = Grid::shape.shape.y;
    static constexpr integer nxtot = Grid::full_shape.shape.x;
    static constexpr integer nytot = Grid::full_shape.shape.y;
    static constexpr integer nhx = Grid::halo_shape.shape.x;
    static constexpr integer nhy = Grid::halo_shape.shape.y;

    using value_type = T;
    using grid_type = Grid;
    using field = xtensor_fixed<value_type, xshape<>>;

    ShallowData() = delete;
    ShallowData(Grid grid)
      : grid{grid}
    {}

    decltype(auto)
    h(integer i, integer j){ return h_(i, j); }

    decltype(auto)
    h(){ return h_; }

  private:
    const grid_type grid;
    field h_;
    field u_;
    field v_;
  };

  template<typename T>
  ShallowData(Subgrid<T>) -> ShallowData<T,Subgrid<T>>;

} // end of namespace Shallow::Details

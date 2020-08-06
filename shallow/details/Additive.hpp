#pragma once

//
// ... Shallow header files
//
#include <shallow/details/import.hpp>

namespace Shallow::Details
{
  template<typename T>
  struct Additive : CRTP<Additive, T>
  {
    friend constexpr T
    operator +( Additive<T> const& u, Additive<T> const& v){
      return {
        static_cast<T const&>(u).x + static_cast<T const&>(v).x,
        static_cast<T const&>(u).y + static_cast<T const&>(v).y
      };
    }
  };// end of class Additive
} // end of namespace Shallow::Details

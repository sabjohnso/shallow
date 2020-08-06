#pragma once

//
// ... Shallow header files
//
#include <shallow/details/import.hpp>
#include <shallow/details/Vec2.hpp>

namespace Shallow::Details
{

  template<typename T>
  struct EuclideanArithmetic : CRTP<EuclideanArithmetic, T>
  {
    friend constexpr T
    operator +( EuclideanArithmetic<T> const& u, EuclideanArithmetic<T> const& v){
      return {
        static_cast<T const&>(u).x + static_cast<T const&>(v).x,
        static_cast<T const&>(u).y + static_cast<T const&>(v).y
      };
    }

    friend constexpr T
    operator -( EuclideanArithmetic<T> const& u, EuclideanArithmetic<T> const& v){
      return {
        static_cast<T const&>(u).x - static_cast<T const&>(v).x,
        static_cast<T const&>(u).y - static_cast<T const&>(v).y
      };
    }

    friend constexpr T
    operator -( EuclideanArithmetic<T> const& u){
      return {
       - static_cast<T const&>(u).x,
       - static_cast<T const&>(u).y
      };
    }

    template<typename Val>
    friend constexpr T
    operator *(Val s, EuclideanArithmetic<T> const& u){
      return
        {s * static_cast<T const&>(u).x,
         s * static_cast<T const&>(u).y};
    }

    template<typename Val>
    friend constexpr T
    operator *(EuclideanArithmetic<T> const& u, Val s){
      return s*u;
    }

    template<typename Val>
    friend constexpr T
    operator /(EuclideanArithmetic<T> const& u, Val s){
      return
        {static_cast<T const&>(u).x / s,
         static_cast<T const&>(u).y / s};

    }

    friend constexpr auto
    dot(EuclideanArithmetic<T> const& u, EuclideanArithmetic<T> const& v){
      return
        static_cast<T const&>(u).x * static_cast<T const&>(v).x +
        static_cast<T const&>(u).y * static_cast<T const&>(v).y;
    }

    template<typename V>
    friend constexpr V
    coerce(Type<V>, EuclideanArithmetic<T> const& u){
      return
        {static_cast<T const&>(u).x,
         static_cast<T const&>(u).y};
    }

  }; // end of struct EuclideanArithmetic
} // end of namespace Shallow::Details

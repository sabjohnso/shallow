#pragma once

namespace Shallow::Details
{
  template<typename T, integer N>
  struct Polynomial
  {
    static_assert(N> 0);
  public:
    static constexpr integer degree = N;
    using value_type = T;
    using coefficients_type = array<value_type, degree>;

    template<typename T1, typename T2, typename ... Ts>
    constexpr
    Polynomial(T1 c1, T2 c2, Ts ... cs) : coefficients{{c1, c2, cs ... }}
    {}
  private:
    const coefficients_type coefficients;
  };
} // end of namespace Shallow::Details

#pragma once


namespace Shallow::Details
{
  template<typename T = double, template<typename, size_t> class Array = array, typename Integer = integer>
  class Grid
  {
    using integer = Integer
    using value_type = T;

    using values = Array<value_type,2>;
    using integers = Array<integer,2>;
  public:
  private:

  }; // end of class Grid
} // end of namespace Shallow::Details

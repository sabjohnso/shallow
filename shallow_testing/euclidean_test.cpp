//
// ... Standard header files
//
#include <vector>
#include <type_traits>

//
// ... Test header files
//
#include <gtest/gtest.h>

//
// ... External header files
//
#include <type_utility/type_utility.hpp>

//
// ... Shallow header files
//
#include <shallow/details/Euclidean.hpp>
#include <shallow/details/Euclidean.hpp>

namespace Shallow::Testing
{
  namespace // anonymous
  {
    using std::is_same_v;

    using TypeUtility::type;

    using Shallow::Details::Vec2;
    using Shallow::Details::EuclideanArithmetic;


    template<typename T>
    struct Euclidean : Vec2<T>, EuclideanArithmetic<Euclidean<T>>
    {
      using Vec2<T>::Vec2;
    }; // end of struct Euclidean

    template<typename T>
    Euclidean(T x, T y) -> Euclidean<T>;

    constexpr double a = 3.0;
    constexpr double b = 4.0;
    constexpr double c = 5.0;
    constexpr double d = 6.0;


  } // end of anonymous namespace

  TEST(Euclidean, Construction){
    constexpr Euclidean v{a, b};
    ASSERT_EQ(v.x, a);
    ASSERT_EQ(v.y, b);
  }
  TEST(Euclidean, CopyConstruction){
    constexpr Euclidean v{a, b};
    constexpr auto u = v;
    static_assert(is_same_v<decltype(u),decltype(v)>);
    ASSERT_EQ(u.x, a);
    ASSERT_EQ(u.y, b);
  }

  TEST(Euclidean, Addition){

    constexpr Euclidean u{a, b};
    constexpr Euclidean v{c, d};
    constexpr auto w = u + v;
    ASSERT_EQ(w.x, a+c);
    ASSERT_EQ(w.y, b+d);
  }

  TEST(Euclidean, Subtraction){
    constexpr Euclidean u{a, b};
    constexpr Euclidean v{c, d};
    constexpr auto w = u - v;
    ASSERT_EQ(w.x, a-c);
    ASSERT_EQ(w.y, b-d);
  }

  TEST(Euclidean, Negation){
    constexpr Euclidean u{a, b};
    constexpr auto v = -u;
    ASSERT_EQ(v.x, -a);
    ASSERT_EQ(v.y, -b);
  }

  TEST(Euclidean, LeftScale){
    constexpr Euclidean u{a, b};
    constexpr auto v = c * u;
    ASSERT_EQ( v.x, c*a);
    ASSERT_EQ( v.y, c*b);
  }

  TEST(Euclidean, RightScale){
    constexpr Euclidean u{a, b};
    constexpr auto v = u*c;
    ASSERT_EQ( v.x, c*a);
    ASSERT_EQ( v.y, c*b);
  }

  TEST(Euclidean, DivideScale){
    constexpr Euclidean u{a, b};
    constexpr auto v = u/c;
    ASSERT_EQ( v.x, a/c);
    ASSERT_EQ( v.y, b/c);
  }

  TEST(Euclidean, Dot){
    constexpr Euclidean u{a, b};
    constexpr Euclidean v{c, d};
    constexpr auto e = dot(u, v);
    ASSERT_EQ(e, a*c + b*d);
  }

  TEST(Eucliean, Coercion){
    constexpr Euclidean u{a, b};
    auto xs = coerce(type<std::vector<double>>, u);
    ASSERT_EQ(xs[0], a);
    ASSERT_EQ(xs[1], b);
  }

} // end of namespace Shallow::Testing

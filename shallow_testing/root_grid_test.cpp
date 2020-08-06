//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... External header files
//
#include <nlohmann/json.hpp>

//
// ... Shallow header files
//
#include <shallow/details/RootGrid.hpp>

namespace Shallow::Testing
{
  namespace // anonymous
  {
    using ::Shallow::Details::RootGrid;
    using ::nlohmann::json;
  } // end of anonymous namespace

  TEST(RootGrid, Construction){
    constexpr double a = 0.0;
    constexpr double b = 1.0;
    constexpr double c = 2.0;
    constexpr double d = 3.0;
    RootGrid<double> rg{{a, b}, {c, d}};

    ASSERT_EQ(rg.origin(0), a);
    ASSERT_EQ(rg.origin(1), b);


  }

} // end of namespace Shallow::Testing

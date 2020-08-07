//
// ... Standard header files
//
#include <iostream>
#include <algorithm>
#include <iterator>

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
#include <shallow/details/ShallowData.hpp>

namespace Shallow::Testing
{
  namespace // anonymous
  {
    using ::Shallow::Details::RootGrid;
    using ::Shallow::Details::Subgrid;
    using ::Shallow::Details::Origin;
    using ::Shallow::Details::Spacing;
    using ::Shallow::Details::Offset;
    using ::Shallow::Details::ShallowData;

  } // end of anonymous namespace

  TEST(ShallowData, Construction){
    ShallowData data{
      Subgrid{
        RootGrid{
          Origin{0.0, 0.0},
          Spacing{1.0, 1.0}},
        Offset{10, 20},
        2}};

    auto h = data.h();
    std::for_each(
      std::begin(h), std::end(h),
      [](auto& x){
        x = 1.0;
      });

    EXPECT_TRUE(false);

  }

} // end of namespace Shallow::Testing

//
// ... Testing header files
//
#include <gtest/gtest.h>


//
// ... Shallow header files
//
#include <shallow/details/RootGrid.hpp>
#include <shallow/details/Subgrid.hpp>

namespace Shallow::Testing
{
  namespace // anonymous
  {
    using ::Shallow::Details::RootGrid;
    using ::Shallow::Details::Subgrid;
    using ::Shallow::Details::Origin;
    using ::Shallow::Details::Spacing;
    using ::Shallow::Details::Offset;
  } // end of anonymous namespace

  TEST(Subgrid, Construction){
    Subgrid sg{
      RootGrid{
        Origin{0.0, 0.0},
        Spacing{1.0, 1.0}},
      Offset{10, 20},
      2};
    ASSERT_EQ(sg.spacing(0), 0.25);
    ASSERT_EQ(sg.spacing(1), 0.25);
  }

} // end of namespace Shallow::Testing

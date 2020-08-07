#pragma once

//
// ... Standard header files
//
#include <cmath>
#include <utility>
#include <array>
#include <iostream>
#include <type_traits>

//
// ... External header files
//
#include <nlohmann/json.hpp>
#include <type_utility/type_utility.hpp>
#include <xtensor/xfixed.hpp>
#include <xtensor/xview.hpp>


//
// ... Shallow header files
//
#include <shallow/config.hpp>


namespace Shallow::Details
{
  using ::Shallow::Config::integer;

  using std::exp2;

  using std::forward;
  using std::move;

  using std::array;

  using std::ostream;

  using std::is_same_v;

  using nlohmann::json;

  using xt::xtensor_fixed;
  using xt::xshape;
  using xt::range;
  using xt::all;
  using xt::drop;
  using xt::keep;
  using xt::view;



  using TypeUtility::Type;
  using TypeUtility::type;
  using TypeUtility::CRTP;

} // end of namespace Shallow::Details

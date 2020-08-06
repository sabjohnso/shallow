#pragma once

//
// ... Standard header files
//
#include <cstdint>

namespace Shallow::Config
{


  struct Info {
    static constexpr char name[] = "Project";
    struct Version {
      static constexpr int major = ;
      static constexpr int minor = ;
      static constexpr int patch = ;
    };
    struct Compilers
    {
      struct C {
        static constexpr char cmake_c_compiler [] = "/usr/bin/cc";
        static constexpr char cmake_c_flags [] = "";
        static constexpr char cmake_c_flags_release [] = "-O3 -DNDEBUG";
        static constexpr char cmake_c_flags_debug [] = "-g";
        static constexpr char cmake_c_flags_relwithdebinfo [] = "-O2 -g -DNDEBUG";
        static constexpr char cmake_c_flags_minsizerel [] = "-Os -DNDEBUG";
      };
      struct CXX {
        static constexpr char cmake_cxx_compiler [] = "/usr/bin/c++";
        static constexpr char cmake_cxx_flags [] = "-Wall -Wextra -pedantic -Werror";
        static constexpr char cmake_cxx_flags_release [] = "-O3 -DNDEBUG";
        static constexpr char cmake_cxx_flags_debug [] = "-g";
        static constexpr char cmake_cxx_flags_relwithdebinfo [] = "-O2 -g -DNDEBUG";
        static constexpr char cmake_cxx_flags_minsizerel [] = "-Os -DNDEBUG";
      };
    };
  };

  using integer = ;

} // end of namespace shallow::Config

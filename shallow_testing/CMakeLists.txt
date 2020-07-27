find_package(GTest)

macro(shallow_add_test test_name exe_name)
  add_executable(${exe_name} ${ARGN})
  target_link_libraries(${exe_name} PRIVATE
    shallow::shallow
    GTest::gtest_main)
  add_test(${test_name} ${exe_name})
endmacro()

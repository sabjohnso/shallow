find_package(GTest)

macro(shallow_add_test test_name exe_name)
  add_executable(${exe_name} ${ARGN})
  target_link_libraries(${exe_name} PRIVATE
    shallow::header
    GTest::gtest_main)
  add_test(${test_name} ${exe_name})
endmacro()

shallow_add_test(euclidean euclidean_test euclidean_test.cpp)
shallow_add_test(root_grid root_grid_test root_grid_test.cpp)
shallow_add_test(subgrid subgrid_test subgrid_test.cpp)
shallow_add_test(shallow_data shallow_data_test shallow_data_test.cpp)



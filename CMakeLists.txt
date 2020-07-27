cmake_minimum_required(VERSION 3.12)

project(shallow VERSION 0.1.0 LANGUAGES C CXX)

option(shallow_BUILD_TESTING "Build the shallow tests" ON)

include(GNUInstallDirs)
set(shallow_INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR})
set(shallow_INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR})
set(shallow_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR})
set(shallow_INSTALL_CONFDIR ${shallow_INSTALL_LIBDIR}/cmake/shallow-${PROJECT_VERSION})

list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
include(shallow_deps)

add_subdirectory(shallow)

if(shallow_BUILD_TESTING)
  include(CTest)
  if(BUILD_TESTING)
    add_subdirectory(shallow_testing)
  endif()
endif()

install(EXPORT shallow_EXPORTS
  NAMESPACE shallow::
  FILE shallow-exports.cmake
  DESTINATION ${shallow_INSTALL_CONFDIR})

configure_file(shallow-config.cmake.in shallow-config.cmake)
install(FILES ${PROJECT_BINARY_DIR}/shallow-config.cmake
  DESTINATION ${shallow_INSTALL_CONFDIR})









configure_file(config.hpp.in config.hpp)

add_library(shallow_header INTERFACE)
set_target_properties(shallow_header
  PROPERTIES
    EXPORT_NAME header)
target_include_directories(shallow_header
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${shallow_INSTALL_INCLUDEDIR}>)
target_link_libraries(shallow_header
  INTERFACE
  Boost::boost)
  add_library(shallow::header ALIAS shallow_header)

add_subdirectory(app)

install(TARGETS shallow_header
  EXPORT shallow_EXPORTS
  RUNTIME DESTINATION ${shallow_INSTALL_BINDIR}
  LIBRARY DESTINATION ${shallow_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${shallow_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  DESTINATION ${shallow_INSTALL_INCLUDEDIR})

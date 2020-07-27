configure_file(config.hpp.in config.hpp)

add_library(shallow INTERFACE)
target_include_directories(shallow
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${shallow_INSTALL_INCLUDEDIR}>)

add_library(shallow::shallow ALIAS shallow)
  
install(TARGETS shallow
  EXPORT shallow_EXPORTS
  RUNTIME DESTINATION ${shallow_INSTALL_BINDIR}
  LIBRARY DESTINATION ${shallow_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${shallow_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  DESTINATION ${shallow_INSTALL_INCLUDEDIR})

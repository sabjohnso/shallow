add_executable(shallow shallow.cpp
  Driver.hpp Driver.cpp
  ExceptionHandler.hpp ExceptionHandler.cpp
  RuntimeConfig.hpp RuntimeConfig.cpp)

target_link_libraries(shallow
  shallow::header
  Threads::Threads
  MPI::MPI_CXX
  nlohmann_json::nlohmann_json
  Boost::program_options)

install(TARGETS shallow
  EXPORT shallow_EXPORTS
  RUNTIME DESTINATION ${shallow_INSTALL_BINDIR}
  LIBRARY DESTINATION ${shallow_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${shallow_INSTALL_LIBDIR})

# Download and unpack restclient-cpp at configure time
configure_file(CMakeLists.txt.in restclient-cpp-download/CMakeLists.txt)
# Call CMake to download and restclient-cpp
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/restclient-cpp-download )
if(result)
  message(FATAL_ERROR "CMake step for restclient-cpp failed: ${result}")
endif()
# Build the downloaded restclient-cpp
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/restclient-cpp-download )
if(result)
  message(FATAL_ERROR "Build step for restclient-cpp failed: ${result}")
endif()

# Add restclient-cpp directly to our build. This defines
# the restclient-cpp targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/restclient-cpp-src
                 ${CMAKE_CURRENT_BINARY_DIR}/restclient-cpp-build)

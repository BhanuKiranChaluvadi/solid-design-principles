# Download and unpack rapidjson at configure time
configure_file(CMakeLists.txt.in rapidjson-download/CMakeLists.txt)
# Call CMake to download and rapidjson
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/rapidjson-download )
if(result)
  message(FATAL_ERROR "CMake step for rapidjson failed: ${result}")
endif()
# Build the downloaded rapidjson
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/rapidjson-download )
if(result)
  message(FATAL_ERROR "Build step for rapidjson failed: ${result}")
endif()

# Add rapidjson directly to our build. This defines
# the rapidjson targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/rapidjson-src
                 ${CMAKE_CURRENT_BINARY_DIR}/rapidjson-build)

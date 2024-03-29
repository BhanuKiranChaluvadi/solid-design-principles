# Set the minimum version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (adaptor)

add_subdirectory(3rd_party/restclient-cpp)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp
    src/MovieApiAdapter.cpp
    src/MovieApiAdapter2.cpp
    src/MovieApiAdapter3.cpp
    src/MovieDbRepository.cpp
    src/MovieDbRepository.cpp
    src/MovieManager.cpp
    src/TheMovieDbApi.cpp
)

# Add an executable with the above sources
add_executable(adapter ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(adapter
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
        ${restclient-cpp_SOURCE_DIR}/include
        ${restclient-cpp_BINARY_DIR}/include
        ${PROJECT_SOURCE_DIR}/3rd_party
)


target_link_libraries(adapter
    restclient-cpp
)   
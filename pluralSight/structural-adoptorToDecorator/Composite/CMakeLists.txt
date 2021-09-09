# Set the minimum version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (composite)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp
)

# Add an executable with the above sources
add_executable(composite ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(composite
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
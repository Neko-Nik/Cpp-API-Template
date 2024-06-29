cmake_minimum_required(VERSION 3.10)

# Project name and version
project(NekoNikCppAPI VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the required packages
find_package(Boost REQUIRED COMPONENTS system)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    main.cpp
    src/base_endpoints.cpp
    src/logger.cpp
)

# Target executable
add_executable(main_api ${SOURCES})

# Set the output directory for the executable
set_target_properties(main_api PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

# Include directories
target_include_directories(main_api PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Find and link against Boost if needed
find_package(Boost REQUIRED COMPONENTS system)
if(Boost_FOUND)
    target_link_libraries(main_api PRIVATE Boost::system)
endif()

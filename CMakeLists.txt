cmake_minimum_required (VERSION 2.8)
cmake_policy(SET CMP0048 NEW)
project (example_cpp_lib1 VERSION 1.0.1)

# Use CMAKE_INSTALL_*DIR variables.
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add include directories.
include_directories(include)

# Set sources to compile.
set(SOURCES
  src/example_cpp_lib1/foo.cpp)

# Set public headers.
set(HEADERS
  include/example_cpp_lib1/foo.hpp)

# Create a shared library.
add_library(example_cpp_lib1 SHARED ${SOURCES})

# Set version of shared library.
set_target_properties(example_cpp_lib1 PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER ${HEADERS})

# Set private include directory.
target_include_directories(example_cpp_lib1 PRIVATE include)

# Install.
install(TARGETS example_cpp_lib1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

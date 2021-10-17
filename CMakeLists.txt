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

# Find sources and headers.
file(GLOB_RECURSE EXAMPLE_CPP_LIB1_SOURCE_FILES "src/*.cpp" "src/*.hpp*")
file(GLOB_RECURSE EXAMPLE_CPP_LIB1_HEADER_FILES "include/*.hpp*")

# Create a shared library.
add_library(${PROJECT_NAME} SHARED ${EXAMPLE_CPP_LIB1_HEADER_FILES} ${EXAMPLE_CPP_LIB1_SOURCE_FILES})

# Set version of shared library.
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER ${EXAMPLE_CPP_LIB1_HEADER_FILES})

# Set include directories.
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_include_directories(${PROJECT_NAME} PRIVATE src/)


# Install.
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

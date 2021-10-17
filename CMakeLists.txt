cmake_minimum_required (VERSION 3.21.2)
cmake_policy(SET CMP0048 NEW)
project (example_cpp_lib1 VERSION 1.0.0)

# CMake stuff we need.
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find sources and headers.
file(GLOB_RECURSE EXAMPLE_CPP_LIB1_SOURCE_FILES "src/*.cpp" "src/*.hpp*")
file(GLOB_RECURSE EXAMPLE_CPP_LIB1_HEADER_FILES "include/*.hpp*")

# Create a shared library.
add_library(${PROJECT_NAME} SHARED ${EXAMPLE_CPP_LIB1_HEADER_FILES} ${EXAMPLE_CPP_LIB1_SOURCE_FILES})

# Set version of shared library.
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER ${EXAMPLE_CPP_LIB1_HEADER_FILES}
    )

# Set include directories.
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_include_directories(${PROJECT_NAME} PRIVATE src/)

# Install.
install(TARGETS ${PROJECT_NAME} # EXPORT ExampleCppLib1Config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

set(EXAMPLE_CPP_LIB1_INCLUDE_DIR include)

# Create module config.
configure_package_config_file(ExampleCppLib1Config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/ExampleCppLib1Config.cmake
    INSTALL_DESTINATION cmake
    PATH_VARS EXAMPLE_CPP_LIB1_INCLUDE_DIR)

# Create module version.
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ExampleCppLib1ConfigVersion.cmake
    VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
    COMPATIBILITY SameMajorVersion)

# Install cmake files.
install(
    FILES
      ${CMAKE_CURRENT_BINARY_DIR}/ExampleCppLib1Config.cmake
      ${CMAKE_CURRENT_BINARY_DIR}/ExampleCppLib1ConfigVersion.cmake
    DESTINATION cmake )

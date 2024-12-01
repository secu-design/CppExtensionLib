cmake_minimum_required(VERSION 3.19)
project(CppExtensionLib)

# Output the compiler information
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add source files
set(SOURCE_FILES
    "src/ExtString.cpp"
    "src/ExtConsole.cpp"
    "include/ExtString.hpp"
    "include/ExtConsole.hpp"
)

# Add libraries
add_library(CppExtensionLib SHARED ${SOURCE_FILES})
add_library(CppExtensionLibStatic STATIC ${SOURCE_FILES})

# Project settings (Place after add_library)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CppExtensionLib PROPERTY CXX_STANDARD 20)
  set_property(TARGET CppExtensionLibStatic PROPERTY CXX_STANDARD 20)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror=unused-result -fPIC")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /permissive-")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Zi /Od /RTC1")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /DNDEBUG")
endif ()

# Include directories
target_include_directories(CppExtensionLib PUBLIC ${CMAKE_SOURCE_DIR}/include)

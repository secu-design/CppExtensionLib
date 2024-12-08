cmake_minimum_required(VERSION 3.19)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/CMake/toolchain-general.cmake")
project(CppExtensionLib VERSION 0.1.0)

# Output the compiler information
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")

# Add source files
set(SOURCE_FILES
    "src/ExtString.cpp"
    "src/ExtConsole.cpp"
    "include/ExtString.hpp"
    "include/ExtConsole.hpp"
)

# Configure targets
add_library(CppExtensionLib SHARED ${SOURCE_FILES})
add_library(CppExtensionLibStatic STATIC ${SOURCE_FILES})
add_custom_target(AllTargets DEPENDS CppExtensionLib CppExtensionLibStatic)
set_target_properties(CppExtensionLib PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
)

# Include directories
target_include_directories(CppExtensionLib PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(CppExtensionLibStatic PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Install the library
install(TARGETS CppExtensionLib
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
install(TARGETS CppExtensionLibStatic
        ARCHIVE DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include)

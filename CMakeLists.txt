cmake_minimum_required(VERSION 3.19)
project(CppExtensionLib VERSION 0.1.0)
project(CppExtensionLibStatic VERSION 0.1.0)

enable_testing()
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/CMake/toolchain-general.cmake")

# Output the compiler information
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")

add_subdirectory(src)
add_subdirectory(test)

# Install library settings
#install(TARGETS CppExtensionLib
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib
#)
#install(TARGETS CppExtensionLibStatic
#        ARCHIVE DESTINATION lib
#)
#install(DIRECTORY include/ DESTINATION include)

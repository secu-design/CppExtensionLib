# Add source files

set(SOURCE_FILES
   "pch.cpp"
   "System/String.cpp"
   "System/Console.cpp"
   "System/Security/Crypto.cpp" )

# Configure targets
add_library(CppExtensionLibStatic STATIC ${SOURCE_FILES})
add_library(CppExtensionLib SHARED ${SOURCE_FILES})
add_custom_target(AllTargets DEPENDS CppExtensionLib CppExtensionLibStatic)
set_target_properties(CppExtensionLib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# Include directories
set(COMMON_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/System
    ${CMAKE_SOURCE_DIR}/include/System/Security
)
target_include_directories(CppExtensionLib PUBLIC ${COMMON_INCLUDE_DIRS})
target_include_directories(CppExtensionLibStatic PUBLIC ${COMMON_INCLUDE_DIRS})

# Precompiled headers
target_precompile_headers(CppExtensionLibStatic PUBLIC "${CMAKE_SOURCE_DIR}/include/pch.h")
target_precompile_headers(CppExtensionLib REUSE_FROM CppExtensionLibStatic)

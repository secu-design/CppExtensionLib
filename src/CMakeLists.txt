# Add source files
set(SOURCE_FILES
    "System/String.cpp"
    "System/Console.cpp"
    "System/Security/Crypto.cpp")

# Configure targets
add_library(CppExtensionLib SHARED ${SOURCE_FILES})
add_library(CppExtensionLibStatic STATIC ${SOURCE_FILES})
add_custom_target(AllTargets DEPENDS CppExtensionLib CppExtensionLibStatic)
set_target_properties(CppExtensionLib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# Include directories
target_include_directories(CppExtensionLib PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/System
    ${CMAKE_SOURCE_DIR}/include/System/Security
)
target_include_directories(CppExtensionLibStatic PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/System
    ${CMAKE_SOURCE_DIR}/include/System/Security
)

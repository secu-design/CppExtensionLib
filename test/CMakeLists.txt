include(AddGoogleTest)

add_executable(
    unit_tests
    "Test_ExtString.cpp"
    "Test_ExtConsole.cpp"
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_sources(unit_tests PRIVATE "Test_ExtInteger_GNU.cpp")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_sources(unit_tests PRIVATE "Test_ExtInteger_MSVC.cpp")
endif ()

target_link_libraries(
    unit_tests
    PRIVATE CppExtensionLibStatic
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)

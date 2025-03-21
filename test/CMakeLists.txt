include(AddGoogleTest)

add_executable(
    unit_tests
    "Test_String.cpp"
    "Test_Console.cpp"
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_sources(unit_tests PRIVATE "Test_Integer_GNU.cpp")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_sources(unit_tests PRIVATE "Test_Integer_MSVC.cpp")
endif ()

target_link_libraries(
    unit_tests
    PRIVATE CppExtensionLibStatic
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)

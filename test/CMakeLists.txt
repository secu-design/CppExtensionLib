include(AddGoogleTest)

add_executable(
        unit_tests
        "Test_ExtString.cpp"
        "Test_ExtConsole.cpp"
        "Test_ExtInteger.cpp"
)

target_link_libraries(
        unit_tests
        PRIVATE CppExtensionLibStatic
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)

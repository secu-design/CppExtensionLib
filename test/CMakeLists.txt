include(AddGoogleTest)

add_executable(
    unit_tests
    "Test_Integer.cpp"
    "Test_String.cpp"
    "Test_Console.cpp"
    "Test_Crypto_Caesar.cpp"
)

target_link_libraries(
    unit_tests
    PRIVATE CppExtensionLibStatic
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)

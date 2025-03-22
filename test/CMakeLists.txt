include(AddGoogleTest)

add_executable(
    unit_tests
    "Test_String.cpp"
    "Test_Console.cpp"
    "Test_Crypto_Caesar.cpp"
)

target_sources(unit_tests PRIVATE "Test_Integer.cpp")

target_link_libraries(
    unit_tests
    PRIVATE CppExtensionLibStatic
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)

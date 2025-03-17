# TODO

- [ ] Find corrct MSVC compiler flags for CMake to solve the following problem:

    ```cpp
    // NOTE: Value initialization with {} for large negative numbers does not work. (C2397 narrowing conversion error)
    // Only assignment operator works. The error occurs under CMake, but not with the MS build system.

    TEST(Integer_ToHex, CMakeFail) {
        constexpr signed int value{ - 2'147'483'648 };   // Problem unter CMake; Value is interpretet as unsigned long
        const std::string hexNumber{ Integer::ToHex(value) };
        EXPECT_EQ(hexNumber, "80000000");
    }
    ```

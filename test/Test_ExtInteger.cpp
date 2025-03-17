#include <gtest/gtest.h>

#include "ExtInteger.hpp"

using namespace ext;


// Signed integers

TEST(Integer_ToHex, SignedChar_MaxValue) {
    constexpr signed char value{ 127 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "7f");
}

TEST(Integer_ToHex, SignedShort_MaxValue) {
    constexpr signed short value{ 32'767 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "7fff");
}

TEST(Integer_ToHex, SignedInt_MaxValue) {
    constexpr signed int value{ 2'147'483'647 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "7fffffff");
}

TEST(Integer_ToHex, SignedLong_MaxValue) {
    constexpr signed long value{ 2'147'483'647 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "7fffffff");
}

TEST(Integer_ToHex, SignedLongLong_MaxValue) {
    constexpr signed long long value{ 9'223'372'036'854'775'807 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "7fffffffffffffff");
}

// Signed integers -> Negative numbers

TEST(Integer_ToHex, NegativeSignedChar_MaxValue) {
    constexpr signed char value = -128;
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "80");
}

TEST(Integer_ToHex, NegativeSignedShort_MaxValue) {
    constexpr signed short value = -32'768;
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "8000");
}

TEST(Integer_ToHex, NegativeSignedInt) {
    constexpr signed int value = -2'147'483'648;
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "80000000");
}

TEST(Integer_ToHex, NegativeSignedLong) {
    constexpr signed long value = -2'147'483'648;
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "80000000");
}

TEST(Integer_ToHex, NegativeSignedLongLong) {
    constexpr signed long long value = -9'223'372'036'854'775'808;
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "8000000000000000");
}

// Unsigned integers

TEST(Integer_ToHex, UnsignedChar_MaxValue) {
    constexpr unsigned char value{ 255 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "ff");
}

TEST(Integer_ToHex, UnsignedShort_MaxValue) {
    constexpr unsigned short value{ 65'535 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "ffff");
}

TEST(Integer_ToHex, UnsignedInt_MaxValue) {
    constexpr unsigned int value{ 4'294'967'295 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "ffffffff");
}

TEST(Integer_ToHex, UnsignedLong_MaxValue) {
    constexpr unsigned long value{ 4'294'967'295 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "ffffffff");
}

TEST(Integer_ToHex, UnsignedLongLong_MaxValue) {
    constexpr unsigned long long value{ 18'446'744'073'709'551'615 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "ffffffffffffffff");
}

// Other tests

TEST(Integer_ToHex, SignedIntZero) {
    constexpr signed int value{ 0 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "00");
}

TEST(Integer_ToHex, UnsignedIntZero) {
    constexpr unsigned int value{ 0 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "00");
}

// NOTE: Value initialization with {} for large negative numbers does not work. (C2397 narrowing conversion error)
// Only assignment operator works. The error occurs under CMake, but not with the MS build system.

//TEST(Integer_ToHex, CMakeFail) {
//    constexpr signed int value{ - 2'147'483'648 };   // Problem unter CMake; Value is interpretet as unsigned long
//    const std::string hexNumber{ Integer::ToHex(value) };
//    EXPECT_EQ(hexNumber, "80000000");
//}

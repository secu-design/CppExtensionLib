#include <gtest/gtest.h>

#include <limits>

#include "Integer.hpp"

using namespace ext::System;


// Signed integers - Max values

TEST(Integer_ToHex, Char_MaxValue)
{
    constexpr signed char value{ std::numeric_limits<signed char>::max() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "7f");
}

TEST(Integer_ToHex, Short_MaxValue)
{
    constexpr short value{ std::numeric_limits<short>::max() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "7fff");
}

TEST(Integer_ToHex, Int_MaxValue)
{
    constexpr int value{ std::numeric_limits<int>::max() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "7fffffff");
}

#ifdef _MSC_VER
    TEST(Integer_ToHex, Long_MaxValue)
    {
        constexpr long value{ std::numeric_limits<long>::max() };
        const std::string hexNumber{ Integer::ToHex(value) };
        EXPECT_EQ(hexNumber, "7fffffff");
    }
#elif defined(__GNUC__)
    TEST(Integer_ToHex, Long_MaxValue)
    {
        constexpr long value{ std::numeric_limits<long>::max() };
        const std::string hexNumber{ Integer::ToHex(value) };
        EXPECT_EQ(hexNumber, "7fffffffffffffff");
    }
#endif

TEST(Integer_ToHex, LongLong_MaxValue)
{
    constexpr long long value{ std::numeric_limits<long long>::max() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "7fffffffffffffff");
}

// Signed integers -> Min values

TEST(Integer_ToHex, Char_MinValue)
{
    constexpr signed char value{ std::numeric_limits<signed char>::min() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "80");
}

TEST(Integer_ToHex, Short_MinValue)
{
    constexpr short value{ std::numeric_limits<short>::min() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "8000");
}

TEST(Integer_ToHex, Int_MinValue)
{
    constexpr int value{ std::numeric_limits<int>::min() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "80000000");
}

#ifdef _MSC_VER
TEST(Integer_ToHex, Long_MinValue)
    {
        constexpr long value{ std::numeric_limits<long>::min() };
        const std::string hexNumber{ Integer::ToHex(value) };
        EXPECT_EQ(hexNumber, "80000000");
    }
#elif defined(__GNUC__)
    TEST(Integer_ToHex, Long_MinValue)
    {
        constexpr long value{ std::numeric_limits<long>::min() };
        const std::string hexNumber{ Integer::ToHex(value) };
        EXPECT_EQ(hexNumber, "8000000000000000");
    }
#endif

// Unsigned integers -> Max values

TEST(Integer_ToHex, UnsignedChar_MaxValue)
{
    constexpr unsigned char value{ std::numeric_limits<unsigned char>::max() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "ff");
}

TEST(Integer_ToHex, UnsignedShort_MaxValue)
{
    constexpr unsigned short value{ std::numeric_limits<unsigned short>::max() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "ffff");
}

TEST(Integer_ToHex, UnsignedInt_MaxValue)
{
    constexpr unsigned int value{ std::numeric_limits<unsigned int>::max() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "ffffffff");
}

#ifdef _MSC_VER
    TEST(Integer_ToHex, UnsignedLong_MaxValue)
    {
        constexpr unsigned long value{ std::numeric_limits<unsigned long>::max() };
        const std::string hexNumber{ Integer::ToHex(value) };
        EXPECT_EQ(hexNumber, "ffffffff");
    }
#elif defined(__GNUC__)
    TEST(Integer_ToHex, UnsignedLong_MaxValue)
    {
        constexpr unsigned long value{ std::numeric_limits<unsigned long>::max() };
        const std::string hexNumber{ Integer::ToHex(value) };
        EXPECT_EQ(hexNumber, "ffffffffffffffff");
    }
#endif

TEST(Integer_ToHex, UnsignedLongLong_MaxValue) {
    constexpr unsigned long long value{ std::numeric_limits<unsigned long long>::max() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "ffffffffffffffff");
}

// Other tests

TEST(Integer_ToHex, Zero)
{
    constexpr long value{};
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "00");
}

TEST(Integer_ToHex, NegativeZero)
{
    constexpr long value{ -0 };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "00");
}

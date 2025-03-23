#include <gtest/gtest.h>

#include <limits>

#include "Integer.hpp"

using namespace ext::System;

// Signed integers - Max values

TEST(Integer_ToString, Char_MaxValue)
{
    constexpr signed char value = std::numeric_limits<signed char>::max();
    EXPECT_EQ(Integer::ToString(value), "127");
}

TEST(Integer_ToString, Short_MaxValue)
{
    constexpr short value = std::numeric_limits<short>::max();
    EXPECT_EQ(Integer::ToString(value), "32767");
}

TEST(Integer_ToString, Int_MaxValue)
{
    constexpr int value = std::numeric_limits<int>::max();
    EXPECT_EQ(Integer::ToString(value), "2147483647");
}

TEST(Integer_ToString, Long_MaxValue)
{
    constexpr long value = std::numeric_limits<long>::max();
    EXPECT_EQ(Integer::ToString(value), "9223372036854775807");
}

// Signed integers - Min values

TEST(Integer_ToString, Char_MinValue)
{
    constexpr signed char value = std::numeric_limits<signed char>::min();
    EXPECT_EQ(Integer::ToString(value), "-128");
}

TEST(Integer_ToString, Short_MinValue)
{
    constexpr short value = std::numeric_limits<short>::min();
    EXPECT_EQ(Integer::ToString(value), "-32768");
}

TEST(Integer_ToString, Int_MinValue)
{
    constexpr int value = std::numeric_limits<int>::min();
    EXPECT_EQ(Integer::ToString(value), "-2147483648");
}

TEST(Integer_ToString, Long_MinValue)
{
    constexpr long value = std::numeric_limits<long>::min();
    EXPECT_EQ(Integer::ToString(value), "-9223372036854775808");
}

// Unsigned integers - Max values

TEST(Integer_ToString, UnsignedChar_MaxValue)
{
    constexpr unsigned char value = std::numeric_limits<unsigned char>::max();
    EXPECT_EQ(Integer::ToString(value), "255");
}

TEST(Integer_ToString, UnsignedShort_MaxValue)
{
    constexpr unsigned short value = std::numeric_limits<unsigned short>::max();
    EXPECT_EQ(Integer::ToString(value), "65535");
}

TEST(Integer_ToString, UnsignedInt_MaxValue)
{
    constexpr unsigned int value = std::numeric_limits<unsigned int>::max();
    EXPECT_EQ(Integer::ToString(value), "4294967295");
}

TEST(Integer_ToString, UnsignedLong_MaxValue)
{
    constexpr unsigned long value = std::numeric_limits<unsigned long>::max();
    EXPECT_EQ(Integer::ToString(value), "18446744073709551615");
}

// Other tests

TEST(Integer_ToString, Zero)
{
    constexpr long value = 0;
    EXPECT_EQ(Integer::ToString(value), "0");
}

TEST(Integer_ToString, NegativeZero)
{
    constexpr long value = -0;
    EXPECT_EQ(Integer::ToString(value), "0");
}

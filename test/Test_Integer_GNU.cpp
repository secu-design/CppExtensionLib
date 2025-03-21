#include <gtest/gtest.h>

#include <limits>

#include "Integer.hpp"

using namespace ext::System;


// Signed integers - Max values

TEST(Integer_ToHex, GNU_SignedChar_MaxValue)
{
    constexpr signed char value{ std::numeric_limits<signed char>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "7f");
}

TEST(Integer_ToHex, GNU_SignedShort_MaxValue)
{
    constexpr signed short value{ std::numeric_limits<signed short>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "7fff");
}

TEST(Integer_ToHex, GNU_SignedInt_MaxValue)
{
    constexpr signed int value{ std::numeric_limits<signed int>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "7fffffff");
}

TEST(Integer_ToHex, GNU_SignedLong_MaxValue)
{
    constexpr signed long value{ std::numeric_limits<signed long>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "7fffffffffffffff");
}

TEST(Integer_ToHex, GNU_SignedLongLong_MaxValue)
{
    constexpr signed long long value{ std::numeric_limits<signed long long>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "7fffffffffffffff");
}

// Signed integers -> Min values

TEST(Integer_ToHex, GNU_SignedChar_MinValue)
{
    constexpr signed char value{ std::numeric_limits<signed char>::min() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "80");
}

TEST(Integer_ToHex, GNU_SignedShort_MinValue)
{
    constexpr signed short value{ std::numeric_limits<signed short>::min() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "8000");
}

TEST(Integer_ToHex, GNU_SignedInt_MinValue)
{
    constexpr signed int value{ std::numeric_limits<signed int>::min() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "80000000");
}

TEST(Integer_ToHex, GNU_SignedLong_MinValue)
{
    constexpr signed long value{ std::numeric_limits<signed long>::min() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "8000000000000000");
}

TEST(Integer_ToHex, GNU_SignedLongLong_MinValue)
{
    constexpr signed long long value{ std::numeric_limits<signed long long>::min() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "8000000000000000");
}

// Unsigned integers -> Max values

TEST(Integer_ToHex, GNU_UnsignedChar_MaxValue)
{
    constexpr unsigned char value{ std::numeric_limits<unsigned char>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "ff");
}

TEST(Integer_ToHex, GNU_UnsignedShort_MaxValue)
{
    constexpr unsigned short value{ std::numeric_limits<unsigned short>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "ffff");
}

TEST(Integer_ToHex, GNU_UnsignedInt_MaxValue)
{
    constexpr unsigned int value{ std::numeric_limits<unsigned int>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "ffffffff");
}

TEST(Integer_ToHex, GNU_UnsignedLong_MaxValue)
{
    constexpr unsigned long value{ std::numeric_limits<unsigned long>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "ffffffffffffffff");
}

TEST(Integer_ToHex, GNU_UnsignedLongLong_MaxValue) {
    constexpr unsigned long long value{ std::numeric_limits<unsigned long long>::max() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "ffffffffffffffff");
}

// Other tests

TEST(Integer_ToHex, GNU_SignedIntZero)
{
    constexpr signed int value{};
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "00");
}

TEST(Integer_ToHex, GNU_UnsignedIntZero)
{
    constexpr unsigned int value{};
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "00");
}

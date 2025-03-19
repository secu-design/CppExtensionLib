#include <gtest/gtest.h>

#include <limits>

#include "ExtInteger.hpp"

using namespace ext;


// Signed integers - Max values

TEST(Integer_ToHex, SignedChar_MaxValue)
{
    constexpr signed char value{ std::numeric_limits<signed char>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "7f");
}

TEST(Integer_ToHex, SignedShort_MaxValue)
{
    constexpr signed short value{ std::numeric_limits<signed short>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "7fff");
}

TEST(Integer_ToHex, SignedInt_MaxValue)
{
    constexpr signed int value{ std::numeric_limits<signed int>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "7fffffff");
}

TEST(Integer_ToHex, SignedLong_MaxValue)
{
    constexpr signed long value{ std::numeric_limits<signed long>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "7fffffffffffffff");
}

TEST(Integer_ToHex, SignedLongLong_MaxValue)
{
    constexpr signed long long value{ std::numeric_limits<signed long long>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "7fffffffffffffff");
}

// Signed integers -> Min values

TEST(Integer_ToHex, SignedChar_MinValue)
{
    constexpr signed char value{ std::numeric_limits<signed char>::min() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "80");
}

TEST(Integer_ToHex, SignedShort_MinValue)
{
    constexpr signed short value{ std::numeric_limits<signed short>::min() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "8000");
}

TEST(Integer_ToHex, SignedInt_MinValue)
{
    constexpr signed int value{ std::numeric_limits<signed int>::min() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "80000000");
}

TEST(Integer_ToHex, SignedLong_MinValue)
{
    constexpr signed long value{ std::numeric_limits<signed long>::min() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "8000000000000000");
}

TEST(Integer_ToHex, SignedLongLong_MinValue)
{
    constexpr signed long long value{ std::numeric_limits<signed long long>::min() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "8000000000000000");
}

// Unsigned integers -> Max values

TEST(Integer_ToHex, UnsignedChar_MaxValue)
{
    constexpr unsigned char value{ std::numeric_limits<unsigned char>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "ff");
}

TEST(Integer_ToHex, UnsignedShort_MaxValue)
{
    constexpr unsigned short value{ std::numeric_limits<unsigned short>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "ffff");
}

TEST(Integer_ToHex, UnsignedInt_MaxValue)
{
    constexpr unsigned int value{ std::numeric_limits<unsigned int>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "ffffffff");
}

TEST(Integer_ToHex, UnsignedLong_MaxValue)
{
    constexpr unsigned long value{ std::numeric_limits<unsigned long>::max() };
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "ffffffffffffffff");
}

TEST(Integer_ToHex, UnsignedLongLong_MaxValue) {
    constexpr unsigned long long value{ std::numeric_limits<unsigned long long>::max() };
    const std::string hexNumber{ Integer::ToHex(value) };
    EXPECT_EQ(hexNumber, "ffffffffffffffff");
}

// Other tests

TEST(Integer_ToHex, SignedIntZero)
{
    constexpr signed int value{};
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "00");
}

TEST(Integer_ToHex, UnsignedIntZero)
{
    constexpr unsigned int value{};
    const std::string hexNumber{Integer::ToHex(value)};
    EXPECT_EQ(hexNumber, "00");
}

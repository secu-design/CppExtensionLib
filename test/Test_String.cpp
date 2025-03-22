#include "pch.h"
#include <gtest/gtest.h>

#include "String.hpp"

using namespace ext::System;


// TrimStart

TEST(String_TrimStart, TrimLeadingSpaces) {
    const String str("   TestString");
    EXPECT_EQ(str.TrimStart(), "TestString");
}
TEST(String_TrimStart, MixedWhitespace) {
    const String str("\t\n\v\f\r TestString");
    EXPECT_EQ(str.TrimStart(), "TestString");
}
TEST(String_TrimStart, NoLeadingWhitespace) {
    const String str("TestString");
    EXPECT_EQ(str.TrimStart(), "TestString");
}
TEST(String_TrimStart, OnlyWhitespace) {
    const String str("   ");
    EXPECT_EQ(str.TrimStart(), "");
}
TEST(String_TrimStart, EmptyString) {
    const String str("");
    EXPECT_EQ(str.TrimStart(), "");
}

// TrimEnd

TEST(String_TrimEnd, TrimTrailingSpaces) {
    const String str("TestString   ");
    EXPECT_EQ(str.TrimEnd(), "TestString");
}
TEST(String_TrimEnd, MixedWhitespace) {
    const String str("TestString\t\n\v\f\r ");
    EXPECT_EQ(str.TrimEnd(), "TestString");
}
TEST(String_TrimEnd, NoTrailingWhitespace) {
    const String str("TestString");
    EXPECT_EQ(str.TrimEnd(), "TestString");
}
TEST(String_TrimEnd, OnlyWhitespace) {
    const String str("   ");
    EXPECT_EQ(str.TrimEnd(), "");
}
TEST(String_TrimEnd, EmptyString) {
    const String str("");
    EXPECT_EQ(str.TrimEnd(), "");
}

// Trim

TEST(String_Trim, TrimLeadingSpaces) {
    const String str("   TestString");
    EXPECT_EQ(str.Trim(), "TestString");
}
TEST(String_Trim, TrimTrailingSpaces) {
    const String str("TestString   ");
    EXPECT_EQ(str.Trim(), "TestString");
}
TEST(String_Trim, MixedLeadingWhitespace) {
    const String str("\t\n\v\f\r TestString");
    EXPECT_EQ(str.Trim(), "TestString");
}
TEST(String_Trim, MixedTrailingWhitespace) {
    const String str("TestString\t\n\v\f\r ");
    EXPECT_EQ(str.Trim(), "TestString");
}
TEST(String_Trim, NoWhitespace) {
    const String str("TestString");
    EXPECT_EQ(str.Trim(), "TestString");
}
TEST(String_Trim, OnlyWhitespace) {
    const String str("   ");
    EXPECT_EQ(str.Trim(), "");
}
TEST(String_Trim, OnlyMixedWhitespace) {
    const String str("\t\n\v\f\r ");
    EXPECT_EQ(str.Trim(), "");
}
TEST(String_Trim, EmptyString) {
    const String str("");
    EXPECT_EQ(str.Trim(), "");
}

// ToLower_Ascii7

TEST(String_ToLower, AllUppercase) {
    const String str("TESTSTRING");
    EXPECT_EQ(str.ToLower_Ascii7(), "teststring");
}
TEST(String_ToLower, AllLowercase) {
    const String str("teststring");
    EXPECT_EQ(str.ToLower_Ascii7(), "teststring");
}
TEST(String_ToLower, MixedCase) {
    const String str("TeStStRiNg");
    EXPECT_EQ(str.ToLower_Ascii7(), "teststring");
}
TEST(String_ToLower, NumbersAndSymbols) {
    const String str("Test123!@#,`");
    EXPECT_EQ(str.ToLower_Ascii7(), "test123!@#,`");
}
TEST(String_ToLower, NonASCIICharacters) {
    const String str("TÉstrtRÍNG");
    EXPECT_NE(str.ToLower_Ascii7(), "téststríng");
}
TEST(String_ToLower, WhitespaceHandling) {
    const String str(" Test String ");
    EXPECT_EQ(str.ToLower_Ascii7(), " test string ");
}
TEST(String_ToLower, EmptyString) {
    const String str("");
    EXPECT_EQ(str.ToLower_Ascii7(), "");
}

// ToUpper_Ascii7

TEST(String_ToUpper, AllUppercase) {
    const String str("TESTSTRING");
    EXPECT_EQ(str.ToUpper_Ascii7(), "TESTSTRING");
}
TEST(String_ToUpper, AllLowercase) {
    const String str("teststring");
    EXPECT_EQ(str.ToUpper_Ascii7(), "TESTSTRING");
}
TEST(String_ToUpper, MixedCase) {
    const String str("TeStStRiNg");
    EXPECT_EQ(str.ToUpper_Ascii7(), "TESTSTRING");
}
TEST(String_ToUpper, NumbersAndSymbols) {
    const String str("Test123!@#,`");
    EXPECT_EQ(str.ToUpper_Ascii7(), "TEST123!@#,`");
}
TEST(String_ToUpper, NonASCIICharacters) {
    const String str("TéstStríng");
    EXPECT_NE(str.ToUpper_Ascii7(), "TÉSTSTRÍNG");
}
TEST(String_ToUpper, WhitespaceHandling) {
    const String str(" Test String ");
    EXPECT_EQ(str.ToUpper_Ascii7(), " TEST STRING ");
}
TEST(String_ToUpper, EmptyString) {
    const String str("");
    EXPECT_EQ(str.ToUpper_Ascii7(), "");
}

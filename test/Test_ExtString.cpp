#include <gtest/gtest.h>

#include "ExtString.hpp"

// TrimStart

TEST(String_TrimStart, TrimLeadingSpaces) {
    const ext::String str("   TestString");
    EXPECT_EQ(str.TrimStart(), "TestString");
}
TEST(String_TrimStart, MixedWhitespace) {
    const ext::String str("\t\n\v\f\r TestString");
    EXPECT_EQ(str.TrimStart(), "TestString");
}
TEST(String_TrimStart, NoLeadingWhitespace) {
    const ext::String str("TestString");
    EXPECT_EQ(str.TrimStart(), "TestString");
}
TEST(String_TrimStart, OnlyWhitespace) {
    const ext::String str("   ");
    EXPECT_EQ(str.TrimStart(), "");
}
TEST(String_TrimStart, EmptyString) {
    const ext::String str("");
    EXPECT_EQ(str.TrimStart(), "");
}

// TrimEnd

TEST(String_TrimEnd, TrimTrailingSpaces) {
    const ext::String str("TestString   ");
    EXPECT_EQ(str.TrimEnd(), "TestString");
}
TEST(String_TrimEnd, MixedWhitespace) {
    const ext::String str("TestString\t\n\v\f\r ");
    EXPECT_EQ(str.TrimEnd(), "TestString");
}
TEST(String_TrimEnd, NoTrailingWhitespace) {
    const ext::String str("TestString");
    EXPECT_EQ(str.TrimEnd(), "TestString");
}
TEST(String_TrimEnd, OnlyWhitespace) {
    const ext::String str("   ");
    EXPECT_EQ(str.TrimEnd(), "");
}
TEST(String_TrimEnd, EmptyString) {
    const ext::String str("");
    EXPECT_EQ(str.TrimEnd(), "");
}

// Trim
TEST(String_Trim, TrimLeadingSpaces) {
    const ext::String str("   TestString");
    EXPECT_EQ(str.Trim(), "TestString");
}
TEST(String_Trim, TrimTrailingSpaces) {
    const ext::String str("TestString   ");
    EXPECT_EQ(str.Trim(), "TestString");
}
TEST(String_Trim, MixedLeadingWhitespace) {
    const ext::String str("\t\n\v\f\r TestString");
    EXPECT_EQ(str.Trim(), "TestString");
}
TEST(String_Trim, MixedTrailingWhitespace) {
    const ext::String str("TestString\t\n\v\f\r ");
    EXPECT_EQ(str.Trim(), "TestString");
}
TEST(String_Trim, NoWhitespace) {
    const ext::String str("TestString");
    EXPECT_EQ(str.Trim(), "TestString");
}
TEST(String_Trim, OnlyWhitespace) {
    const ext::String str("   ");
    EXPECT_EQ(str.Trim(), "");
}
TEST(String_Trim, OnlyMixedWhitespace) {
    const ext::String str("\t\n\v\f\r ");
    EXPECT_EQ(str.Trim(), "");
}
TEST(String_Trim, EmptyString) {
    const ext::String str("");
    EXPECT_EQ(str.Trim(), "");
}

// ToLower_Ascii7
TEST(String_ToLower, AllUppercase) {
    const ext::String str("TESTSTRING");
    EXPECT_EQ(str.ToLower_Ascii7(), "teststring");
}
TEST(String_ToLower, AllLowercase) {
    const ext::String str("teststring");
    EXPECT_EQ(str.ToLower_Ascii7(), "teststring");
}
TEST(String_ToLower, MixedCase) {
    const ext::String str("TeStStRiNg");
    EXPECT_EQ(str.ToLower_Ascii7(), "teststring");
}
TEST(String_ToLower, NumbersAndSymbols) {
    const ext::String str("Test123!@#,`");
    EXPECT_EQ(str.ToLower_Ascii7(), "test123!@#,`");
}
TEST(String_ToLower, NonASCIICharacters) {
    const ext::String str("TÉstrtRÍNG");
    EXPECT_EQ(str.ToLower_Ascii7(), "téststríng");
}
TEST(String_ToLower, WhitespaceHandling) {
    const ext::String str(" Test String ");
    EXPECT_EQ(str.ToLower_Ascii7(), " test string ");
}
TEST(String_ToLower, EmptyString) {
    const ext::String str("");
    EXPECT_EQ(str.ToLower_Ascii7(), "");
}

// ToUpper_Ascii7
TEST(String_ToUpper, AllUppercase) {
    const ext::String str("TESTSTRING");
    EXPECT_EQ(str.ToUpper_Ascii7(), "TESTSTRING");
}
TEST(String_ToUpper, AllLowercase) {
    const ext::String str("teststring");
    EXPECT_EQ(str.ToUpper_Ascii7(), "TESTSTRING");
}
TEST(String_ToUpper, MixedCase) {
    const ext::String str("TeStStRiNg");
    EXPECT_EQ(str.ToUpper_Ascii7(), "TESTSTRING");
}
TEST(String_ToUpper, NumbersAndSymbols) {
    const ext::String str("Test123!@#,`");
    EXPECT_EQ(str.ToUpper_Ascii7(), "TEST123!@#,`");
}
TEST(String_ToUpper, NonASCIICharacters) {
    const ext::String str("TéstStríng");
    EXPECT_EQ(str.ToUpper_Ascii7(), "TÉSTSTRÍNG");
}
TEST(String_ToUpper, WhitespaceHandling) {
    const ext::String str(" Test String ");
    EXPECT_EQ(str.ToUpper_Ascii7(), " TEST STRING ");
}
TEST(String_ToUpper, EmptyString) {
    const ext::String str("");
    EXPECT_EQ(str.ToUpper_Ascii7(), "");
}

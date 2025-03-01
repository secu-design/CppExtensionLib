#include <gtest/gtest.h>

#include "ExtString.hpp"

// TrimStart

TEST(TrimStartTest, TrimLeadingWhitespace) {
    const ext::String str("   TestString");
    EXPECT_EQ(str.TrimStart(), "TestString");
}

TEST(TrimStartTest, NoLeadingWhitespace) {
    const ext::String str("TestString");
    EXPECT_EQ(str.TrimStart(), "TestString");
}

TEST(TrimStartTest, OnlyWhitespace) {
    const ext::String str("   ");
    EXPECT_EQ(str.TrimStart(), "");
}

TEST(TrimStartTest, EmptyString) {
    const ext::String str("");
    EXPECT_EQ(str.TrimStart(), "");
}

TEST(TrimStartTest, MixedWhitespace) {
    const ext::String str("\t\n\v\f\r TestString");
    EXPECT_EQ(str.TrimStart(), "TestString");
}

// TrimEnd

TEST(TrimEndTest, TrimTrailingWhitespace) {
    const ext::String str("TestString   ");
    EXPECT_EQ(str.TrimEnd(), "TestString");
}

TEST(TrimEndTest, NoTrailingWhitespace) {
    const ext::String str("TestString");
    EXPECT_EQ(str.TrimEnd(), "TestString");
}

TEST(TrimEndTest, OnlyWhitespace) {
    const ext::String str("   ");
    EXPECT_EQ(str.TrimEnd(), "");
}

TEST(TrimEndTest, EmptyString) {
    const ext::String str("");
    EXPECT_EQ(str.TrimEnd(), "");
}

TEST(TrimEndTest, MixedWhitespace) {
    const ext::String str("TestString\t\n\v\f\r ");
    EXPECT_EQ(str.TrimEnd(), "TestString");
}

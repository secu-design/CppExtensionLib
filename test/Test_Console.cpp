#include "pch.h"
#include <gtest/gtest.h>

#include "Console.hpp"

using namespace ext::System;


// Redirect cout and wcout to stringstream and wstringstream
class ConsoleTest : public ::testing::Test {
protected:
    std::stringstream buffer{};
    std::wstringstream wbuffer{};
    std::streambuf* coutbuf{};
    std::wstreambuf* wcoutbuf{};

    void SetUp() override {
        coutbuf = std::cout.rdbuf(buffer.rdbuf());
        wcoutbuf = std::wcout.rdbuf(wbuffer.rdbuf());
    }

    void TearDown() override {
        std::cout.rdbuf(coutbuf);
        std::wcout.rdbuf(wcoutbuf);
    }
};

// Write

TEST_F(ConsoleTest, WriteCharPointer) {
    Console.Write("TestString");
    EXPECT_EQ(buffer.str(), "TestString");
}
TEST_F(ConsoleTest, WriteString) {
    Console.Write(std::string("TestString"));
    EXPECT_EQ(buffer.str(), "TestString");
}
TEST_F(ConsoleTest, WriteWString) {
    Console.Write(std::wstring(L"TestString"));
    EXPECT_EQ(wbuffer.str(), L"TestString");
}

// WriteLine

TEST_F(ConsoleTest, WriteLineCharPointer) {
    Console.WriteLine("TestString");
    EXPECT_EQ(buffer.str(), "TestString\n");
}
TEST_F(ConsoleTest, WriteLineString) {
    Console.WriteLine(std::string("TestString"));
    EXPECT_EQ(buffer.str(), "TestString\n");
}
TEST_F(ConsoleTest, WriteLineWString) {
    Console.WriteLine(std::wstring(L"TestString"));
    EXPECT_EQ(wbuffer.str(), L"TestString\n");
}

#include <gtest/gtest.h>

#include "ExtConsole.hpp"


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
    ext::Console.Write("TestString");
    EXPECT_EQ(buffer.str(), "TestString");
}
TEST_F(ConsoleTest, WriteString) {
    ext::Console.Write(std::string("TestString"));
    EXPECT_EQ(buffer.str(), "TestString");
}
TEST_F(ConsoleTest, WriteWString) {
    ext::Console.Write(std::wstring(L"TestString"));
    EXPECT_EQ(wbuffer.str(), L"TestString");
}

// WriteLine

TEST_F(ConsoleTest, WriteLineCharPointer) {
    ext::Console.WriteLine("TestString");
    EXPECT_EQ(buffer.str(), "TestString\n");
}
TEST_F(ConsoleTest, WriteLineString) {
    ext::Console.WriteLine(std::string("TestString"));
    EXPECT_EQ(buffer.str(), "TestString\n");
}
TEST_F(ConsoleTest, WriteLineWString) {
    ext::Console.WriteLine(std::wstring(L"TestString"));
    EXPECT_EQ(wbuffer.str(), L"TestString\n");
}

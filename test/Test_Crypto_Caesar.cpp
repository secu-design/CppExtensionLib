#include "pch.h"
#include <gtest/gtest.h>

#include <limits>
#include <string>

#include "Crypto.hpp"

using namespace ext::System::Cryptography;


// Caesar

TEST(Crypto_Caesar, Encrypt)
{
    const std::string text("TestString");
    const std::string textHex{ "7e8f9d9e7d9e9c939891" };
    constexpr long    shift{ 42 };

    const std::string encryptedText{ Crypto.Caesar.Encrypt(text, shift) };
    EXPECT_EQ(encryptedText, textHex);
}

TEST(Crypto_Caesar, Decrypt)
{
    const std::string text("TestString");
    const std::string textHex{ "7e8f9d9e7d9e9c939891" };
    constexpr long    shift{ 42 };

    const std::string decryptedText{ Crypto.Caesar.Decrypt(textHex, shift) };
    EXPECT_EQ(decryptedText, text);
}

TEST(Crypto_Caesar, Encrypt_NoText)
{
    const std::string text("");
    const std::string textHex{ "" };
    constexpr long    shift{ 42 };

    const std::string encryptedText{ Crypto.Caesar.Encrypt(text, shift) };
    EXPECT_EQ(encryptedText, textHex);
}

TEST(Crypto_Caesar, Decrypt_NoText)
{
    const std::string text("");
    const std::string textHex{ "" };
    constexpr long    shift{ 42 };

    const std::string decryptedText{ Crypto.Caesar.Decrypt(textHex, shift) };
    EXPECT_EQ(decryptedText, text);
}

TEST(Crypto_Caesar, Encrypt_NoTextShiftZero)
{
    const std::string text("");
    const std::string textHex{ "" };
    constexpr long    shift{};

    const std::string encryptedText{ Crypto.Caesar.Encrypt(text, shift) };
    EXPECT_EQ(encryptedText, textHex);
}

TEST(Crypto_Caesar, Decrypt_NoTextShiftZero)
{
    const std::string text("");
    const std::string textHex{ "" };
    constexpr long    shift{};

    const std::string decryptedText{ Crypto.Caesar.Decrypt(textHex, 0) };
    EXPECT_EQ(decryptedText, text);
}

// Caesar - Shift tests

TEST(Crypto_Caesar, Encrypt_ShiftZero)
{
    const std::string text("TestString");
    const std::string textHex{ "54657374537472696e67" };
    constexpr long    shift{};

    const std::string encryptedText{ Crypto.Caesar.Encrypt(text, shift) };
    EXPECT_EQ(encryptedText, textHex);
}

TEST(Crypto_Caesar, Decrypt_ShiftZero)
{
    const std::string text("TestString");
    const std::string textHex{ "54657374537472696e67" };
    constexpr long    shift{};

    const std::string decryptedText{ Crypto.Caesar.Decrypt(textHex, shift) };
    EXPECT_EQ(decryptedText, text);
}

TEST(Crypto_Caesar, Encrypt_NegativeShift)
{
    const std::string text("TestString");
    const std::string textHex{ "2a3b494a294a483f443d" };
    constexpr long    shift{ -42 };

    const std::string encryptedText{ Crypto.Caesar.Encrypt(text, shift) };
    EXPECT_EQ(encryptedText, textHex);
}

TEST(Crypto_Caesar, Decrypt_NegativeShift)
{
    const std::string text("TestString");
    const std::string textHex{ "2a3b494a294a483f443d" };
    constexpr long    shift{ -42 };

    const std::string decryptedText{ Crypto.Caesar.Decrypt("2a3b494a294a483f443d", shift) };
    EXPECT_EQ(decryptedText, text);
}

TEST(Crypto_Caesar, Encrypt_MinShift)
{
    const std::string text{ "TestString" };
    const std::string textHex{ "80000054800000658000007380000074800000538000007480000072800000698000006e80000067" };
    constexpr long    shift{ std::numeric_limits<long>::min() };

    const std::string encryptedText{ Crypto.Caesar.Encrypt(text, shift) };
    EXPECT_EQ(encryptedText, textHex);
}

TEST(Crypto_Caesar, Decrypt_MinShift)
{
    const std::string text{ "TestString" };
    const std::string textHex{ "80000054800000658000007380000074800000538000007480000072800000698000006e80000067" };
    constexpr long    shift{ std::numeric_limits<long>::min() };

    const std::string decryptedText{ Crypto.Caesar.Decrypt(textHex, shift) };
    EXPECT_EQ(decryptedText, text);
}

TEST(Crypto_Caesar, Encrypt_MaxShift)
{
    const std::string text{ "TestString" };
    const std::string textHex{ "80000053800000648000007280000073800000528000007380000071800000688000006d80000066" };
    constexpr long    shift{ std::numeric_limits<long>::max() };

    const std::string encryptedText{ Crypto.Caesar.Encrypt(text, shift) };
    EXPECT_EQ(encryptedText, textHex);
}

TEST(Crypto_Caesar, Decrypt_MaxShift)
{
    const std::string text{ "TestString" };
    const std::string textHex{ "80000053800000648000007280000073800000528000007380000071800000688000006d80000066" };
    constexpr long    shift{ std::numeric_limits<long>::max() };

    const std::string decryptedText{ Crypto.Caesar.Decrypt(textHex, shift) };
    EXPECT_EQ(decryptedText, text);
}

// Caesar - Other tests

TEST(Crypto_Caesar, Encrypt_SpecialCharacters)
{
    const std::string text("Test! @String#");
    const std::string textHex{ "7e8f9d9e4b4a6a7d9e9c9398914d" };
    constexpr long    shift{ 42 };

    const std::string encryptedText{ Crypto.Caesar.Encrypt(text, shift) };
    EXPECT_EQ(encryptedText, textHex);
}

TEST(Crypto_Caesar, Decrypt_SpecialCharacters)
{
    const std::string text("Test! @String#");
    const std::string textHex{ "7e8f9d9e4b4a6a7d9e9c9398914d" };
    constexpr long    shift{ 42 };

    const std::string decryptedText{ Crypto.Caesar.Decrypt(textHex, shift) };
    EXPECT_EQ(decryptedText, text);
}

TEST(Crypto_Caesar, Encrypt_LongString)
{
    const std::string text(1000, 'A');
    const std::string textHex{ "6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b" };
    constexpr long    shift{ 42 };

    const std::string encryptedText{ Crypto.Caesar.Encrypt(text, shift) };
    EXPECT_EQ(encryptedText, textHex);
}

TEST(Crypto_Caesar, Decrypt_LongString)
{
    const std::string text(1000, 'A');
    const std::string textHex{ "6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b6b" };
    constexpr long    shift{ 42 };

    const std::string decryptedText{ Crypto.Caesar.Decrypt(textHex, shift) };
    EXPECT_EQ(decryptedText, text);
}

#include <gtest/gtest.h>

#include <limits>
#include <string>

#include "Crypto.hpp"

using namespace ext::System::Cryptography;

// Caesar - Basic tests

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
    constexpr long shift{ 42 };

    const std::string encryptedText{ Crypto.Caesar.Encrypt("", shift) };
    EXPECT_EQ(encryptedText, "");
}

TEST(Crypto_Caesar, Decrypt_NoText)
{
    constexpr long shift{ 42 };

    const std::string decryptedText{ Crypto.Caesar.Decrypt("", shift) };
    EXPECT_EQ(decryptedText, "");
}

TEST(Crypto_Caesar, Encrypt_NoTextShiftZero)
{
    constexpr long shift{};

    const std::string encryptedText{ Crypto.Caesar.Encrypt("", shift) };
    EXPECT_EQ(encryptedText, "");
}

TEST(Crypto_Caesar, Decrypt_NoTextShiftZero)
{
    constexpr long shift{};

    const std::string decryptedText{ Crypto.Caesar.Decrypt("", shift) };
    EXPECT_EQ(decryptedText, "");
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

TEST(Crypto_Caesar, Encrypt_NegativeShiftZero)
{
    const std::string text("TestString");
    const std::string textHex{ "54657374537472696e67" };
    constexpr long    shift{ -0 };

    const std::string encryptedText{ Crypto.Caesar.Encrypt(text, shift) };
    EXPECT_EQ(encryptedText, textHex);
}

TEST(Crypto_Caesar, Decrypt_NegativeShiftZero)
{
    const std::string text("TestString");
    const std::string textHex{ "54657374537472696e67" };
    constexpr long    shift{ -0 };

    const std::string decryptedText{ Crypto.Caesar.Decrypt(textHex, shift) };
    EXPECT_EQ(decryptedText, text);
}

TEST(Crypto_Caesar, Encrypt_MinShift)
{
    const std::string text{ "TestString" };
    const std::string textHex{ "54657374537472696e67" };
    constexpr short   shift{ std::numeric_limits<short>::min() };

    const std::string encryptedText{ Crypto.Caesar.Encrypt(text, shift) };
    EXPECT_EQ(encryptedText, textHex);
}

TEST(Crypto_Caesar, Decrypt_MinShift)
{
    const std::string text{ "TestString" };
    const std::string textHex{ "54657374537472696e67" };
    constexpr short   shift{ std::numeric_limits<short>::min() };

    const std::string decryptedText{ Crypto.Caesar.Decrypt(textHex, shift) };
    EXPECT_EQ(decryptedText, text);
}

TEST(Crypto_Caesar, Encrypt_MaxShift)
{
    const std::string text{ "TestString" };
    const std::string textHex{ "53647273527371686d66" };
    constexpr long    shift{ std::numeric_limits<long>::max() };

    const std::string encryptedText{ Crypto.Caesar.Encrypt(text, shift) };
    EXPECT_EQ(encryptedText, textHex);
}

TEST(Crypto_Caesar, Decrypt_MaxShift)
{
    const std::string text{ "TestString" };
    const std::string textHex{ "53647273527371686d66" };
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

TEST(Crypto_Caesar, Decrypt_NoValidHexText)
{
    const std::string textHex{ "NoHexText" };
    constexpr long    shift{ 42 };

    // ReSharper disable once CppNoDiscardExpression
    EXPECT_THROW(Crypto.Caesar.Decrypt(textHex, shift), std::invalid_argument);
}

#include "Crypto.hpp"

#include "Integer.hpp"
#include "String.hpp"


namespace ext::System::Cryptography
{
    CryptClass Crypto;

    /**
     * @brief Encrypts a string using the Caesar cipher algorithm.
     *
     * This function takes a string and a shift value, and returns the encrypted string using the Caesar cipher algorithm.
     * Each character in the input string is shifted by the specified amount and then converted to its hexadecimal representation.
     *
     * @param text The string to encrypt.
     * @param shift The shift value for the Caesar cipher.
     * @return The encrypted hexadecimal string.
     */
    std::string CryptClass::Caesar::Encrypt(const std::string& text, const char shift) const
    {
        std::ostringstream encryptedTextStream;

        for (const char& c : text)
        {
            const auto shiftedChar = c + shift;
            encryptedTextStream << Integer::ToHex(shiftedChar);
        }
        return encryptedTextStream.str();
    }

    /**
     * @brief Decrypts a hexadecimal string using the Caesar cipher algorithm.
     *
     * This function takes a hexadecimal string and a shift value, and returns the decrypted string using the Caesar cipher algorithm.
     * Each character in the input string is converted from its hexadecimal representation and then shifted back by the specified amount.
     *
     * @param textHex The hexadecimal string to decrypt.
     * @param shift The shift value for the Caesar cipher.
     * @return The decrypted string.
     * @throws std::invalid_argument if the input is not a valid hexadecimal string.
     * @throws std::out_of_range if the input is out of range for an integer.
     */
    std::string CryptClass::Caesar::Decrypt(const std::string& textHex, const char shift) const
    {
        std::ostringstream decryptedTextStream;
        std::string        hexSubstring;
        char               decryptedValue{};

        for (size_t i{}; i < textHex.length(); i += 2)
        {
            hexSubstring = textHex.substr(i, 2);
            decryptedValue = String::HexToInt(hexSubstring) - shift;
            decryptedTextStream << decryptedValue;
        }
        return decryptedTextStream.str();
    }

    std::string CryptClass::Xor::Encrypt(const std::string& text, const char key) const
    {
        std::string encryptedText = text;

        for (char& c : encryptedText)
        {
            c ^= key;
        }
        return encryptedText;
    }

    std::string CryptClass::Xor::Decrypt(const std::string& text, const char key) const
    {
        std::string decryptedText = text;

        for (char& c : decryptedText)
        {
            c ^= key;
        }
        return decryptedText;
    }

}   // namespace ext::System::Cryptography

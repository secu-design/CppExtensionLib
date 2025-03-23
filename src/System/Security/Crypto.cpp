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
    std::string CryptClass::Caesar::Encrypt(const std::string& text, long shift) const
    {
        std::ostringstream encryptedTextStream;

        shift %= SHIFT_LIMIT;
        if (shift < 0) {
            shift += SHIFT_LIMIT;
        }

        for (const unsigned char& c : text)
        {
            const auto shiftedChar = (c + shift) % SHIFT_LIMIT;
            encryptedTextStream << Integer::ToHex(shiftedChar);
        }

        return encryptedTextStream.str();
    }

    /**
     * @brief Decrypts a hexadecimal string using the Caesar cipher algorithm.
     *
     * This function takes a hexadecimal string and a shift value, and returns the decrypted string using the Caesar cipher algorithm.
     *
     * @param textHex The hexadecimal string to decrypt.
     * @param shift The shift value for the Caesar cipher.
     * @return The decrypted string.
     * @throws std::invalid_argument if the input is not a valid hexadecimal string.
     * @throws std::out_of_range if the input is out of range for an integer.
     */
    std::string CryptClass::Caesar::Decrypt(const std::string& textHex, long shift) const
    {
        std::ostringstream decryptedTextStream;
        std::string        hexSubstring;
        char               decryptedValue{};

        shift %= SHIFT_LIMIT;
        if (shift < 0) {
            shift += SHIFT_LIMIT;
        }

        for (size_t i = 0; i < textHex.length(); i += 2)
        {
            hexSubstring = textHex.substr(i, 2);
            decryptedValue = (String::HexToInt(hexSubstring) - shift + SHIFT_LIMIT) % SHIFT_LIMIT;
            decryptedTextStream << decryptedValue;
        }

        return decryptedTextStream.str();
    }

}   // namespace ext::System::Cryptography

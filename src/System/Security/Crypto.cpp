#include "Crypto.hpp"

#include "Integer.hpp"
#include "String.hpp"


namespace ext::System::Cryptography
{
    CryptClass Crypto;

    std::string CryptClass::Caesar::Encrypt(const std::string& text, long shift) const
    {
        std::ostringstream encryptedTextStream;
        constexpr auto     SHIFT_LIMIT = 256;

        shift %= SHIFT_LIMIT;
        if (shift < 0) {
            shift += SHIFT_LIMIT;
        }

        for (const char& c : text)
        {
            const long shiftedChar = (static_cast<unsigned char>(c) + shift) % SHIFT_LIMIT;
            encryptedTextStream << Integer::ToHex(shiftedChar);
        }

        return encryptedTextStream.str();
    }

    std::string CryptClass::Caesar::Decrypt(const std::string& textHex, long shift) const
    {
        if (!String::isHex(textHex))
        {
            throw std::invalid_argument("Parameter 'textHex' is not a valid hexadecimal string.");
        }

        constexpr auto     BASE_HEX{ 16 };
        constexpr auto     SHIFT_LIMIT = 256;
        std::ostringstream decryptedTextStream;

        shift %= SHIFT_LIMIT;
        if (shift < 0) {
            shift += SHIFT_LIMIT;
        }

        for (size_t i = 0; i < textHex.length(); i += 2)
        {
            std::string hexSubstring = textHex.substr(i, 2);
            const long  decryptedValue = (std::stol(hexSubstring, nullptr, BASE_HEX) - shift + SHIFT_LIMIT) % SHIFT_LIMIT;
            decryptedTextStream << static_cast<char>(decryptedValue);
        }

        return decryptedTextStream.str();
    }

}   // namespace ext::System::Cryptography

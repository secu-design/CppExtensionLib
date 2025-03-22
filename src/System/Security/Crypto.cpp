#include "pch.h"
#include "Crypto.hpp"

#include "Integer.hpp"
#include "Util.hpp"


namespace ext::System::Cryptography
{
    CryptClass Crypto;

    std::string CryptClass::Caesar::Encrypt(const std::string& text, const long shift) const
    {
        std::ostringstream encryptedStream;

        for (const char& c : text)
        {
            const long shiftedChar = c + shift;
            encryptedStream << Integer::ToHex(shiftedChar);
        }

        return encryptedStream.str();
    }

    std::string CryptClass::Caesar::Decrypt(const std::string& textHex, const long shift) const
    {
        constexpr int      BASE_HEX{ 16 };
        std::ostringstream decryptedStream;
        long               decryptedValue{};
        char               decryptedChar{};

        for (size_t i = 0; i < textHex.length(); i += 2)
        {
            std::string hexSubstring = textHex.substr(i, 2);

            decryptedValue = std::stol(hexSubstring, nullptr, BASE_HEX) - shift;
            decryptedChar = narrow_cast<char>(decryptedValue);
            decryptedStream << decryptedChar;
        }

        return decryptedStream.str();
    }

}   // namespace ext::System::Cryptography

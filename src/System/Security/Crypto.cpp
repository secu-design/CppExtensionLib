#include "Crypto.hpp"

#include "Integer.hpp"
#include "String.hpp"
#include "Util.hpp"


namespace ext::System::Cryptography
{
    CryptClass Crypto;

    std::string CryptClass::Caesar::Encrypt(const std::string& text, const long shift) const
    {
        std::ostringstream encryptedTextStream;

        for (const char& c : text)
        {
            const long shiftedChar = c + shift;
            encryptedTextStream << Integer::ToHex(shiftedChar);
        }

        return encryptedTextStream.str();
    }

    std::string CryptClass::Caesar::Decrypt(const std::string& textHex, const long shift) const
    {
        if (!String::isHex(textHex))
        {
            throw std::invalid_argument("Parameter 'textHex' is not a valid hexadecimal string.");
        }

        constexpr int      BASE_HEX{ 16 };
        std::ostringstream decryptedTextStream;
        long               decryptedValue{};
        char               decryptedChar{};

        for (size_t i = 0; i < textHex.length(); i += 2)
        {
            std::string hexSubstring = textHex.substr(i, 2);

            decryptedValue = std::stol(hexSubstring, nullptr, BASE_HEX) - shift;
            decryptedChar = narrow_cast<char>(decryptedValue);
            decryptedTextStream << decryptedChar;
        }

        return decryptedTextStream.str();
    }

}   // namespace ext::System::Cryptography

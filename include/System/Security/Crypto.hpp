#pragma once

#include <string>


namespace ext::System::Cryptography
{

    struct CryptClass final
    {
        struct Caesar final
        {
            [[nodiscard]] std::string Encrypt(const std::string& text, const char shift) const;
            [[nodiscard]] std::string Decrypt(const std::string& textHex, const char shift) const;
        } Caesar;

        struct Xor final
        {
            [[nodiscard]] std::string Encrypt(const std::string& text, const char key) const;
            [[nodiscard]] std::string Decrypt(const std::string& text, const char key) const;
        } Xor;
    };

    extern CryptClass Crypto;

}   // namespace ext::System::Cryptography

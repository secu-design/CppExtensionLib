#pragma once

#include <string>


namespace ext::System::Cryptography
{

    struct CryptClass final
    {
        struct Caesar final
        {
            [[nodiscard]] std::string Encrypt(const std::string& text, long shift) const;
            [[nodiscard]] std::string Decrypt(const std::string& textHex, long shift) const;
        } Caesar;
    };

    extern CryptClass Crypto;

}   // namespace ext::System::Cryptography

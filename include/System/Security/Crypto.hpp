#pragma once

#include <string>


namespace ext::System::Cryptography
{

    struct CryptClass final
    {
        struct Caesar final
        {
            std::string Encrypt(const std::string& text, const long shift) const;
            std::string Decrypt(const std::string& textHex, const long shift) const;
        } Caesar;
    };

    extern CryptClass Crypto;

}   // namespace ext::System::Cryptography

#pragma once

#include <iomanip>
#include <sstream>
#include <string>


namespace ext::System
{
    struct Integer final
    {
        template <typename T>
        static std::string ToHex(T number);

        template <typename T>
        static std::string ToString(T number);
    };

    template<typename T>
    inline std::string Integer::ToHex(const T number)
    {
        static_assert(std::is_integral_v<T>, "Number must be an integer type.");

        std::ostringstream hexStream;
        hexStream
            << std::hex
            << std::setw(2)
            << std::setfill('0');

        if constexpr (
            std::is_same_v<T, char> ||
            std::is_same_v<T, unsigned char> ||
            std::is_same_v<T, signed char>)
        {
            hexStream << static_cast<unsigned long>(static_cast<unsigned char>(number));
        }
        else
        {
            hexStream << number;
        }

        return hexStream.str();
    }

    template<typename T>
    inline std::string Integer::ToString(const T number)
    {
        static_assert(std::is_integral_v<T>, "Number must be an integer type.");

        std::ostringstream strStream;

        if constexpr (
            std::is_same_v<T, char> ||
            std::is_same_v<T, unsigned char> ||
            std::is_same_v<T, signed char>)
        {
            strStream << static_cast<unsigned long>(number);
        }
        else
        {
            strStream << number;
        }

        return strStream.str();
    }

}   // namespace ext::System

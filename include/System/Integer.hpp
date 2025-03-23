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

    /**
     * @brief Converts an integer to a two-digit hexadecimal string.
     *
     * This function converts the given integer number to its two-digit hexadecimal representation.
     * The type of the number must be an integral type. The resulting hexadecimal string will always
     * be at least two characters long, padded with leading zeros if necessary.
     *
     * @tparam T The type of the number, which must be an integral type.
     * @param number The integer number to convert to a two-digit hexadecimal string.
     * @return std::string The two-digit hexadecimal representation of the given number.
     */
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

    /**
     * @brief Converts an integer to a string.
     *
     * This function converts the given integer number to a string representation. The type of the
     * number must be an integral type. The resulting string will contain the number as a string.
     *
     * @tparam T The type of the number, which must be an integral type.
     * @param number The integer number to convert to a string.
     * @return std::string The string representation of the given number.
     */
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
            strStream << static_cast<long>(number);
        }
        else
        {
            strStream << number;
        }

        return strStream.str();
    }

}   // namespace ext::System

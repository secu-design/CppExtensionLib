#include "../include/ExtString.hpp"

#include <cctype>     // std::tolower, std::toupper
#include <algorithm>  // std::transform

namespace ext
{
    // Initialize the static constants

    const char String::TAB{'\t'};
    const char String::NEWLINE{'\n'};
    const char String::VERTICAL_TAB{'\v'};
    const char String::FORM_FEED{'\f'};
    const char String::CARRIAGE_RETURN{'\r'};
    const char String::SPACE{' '};
    const char* String::WHITESPACE_CHARS{" \t\n\v\f\r"};

    // Implementation of the extended methods

    /**
     * @brief Removes all the leading white-space characters from the current string.
     * 
     * @returns A new string with all the leading white-space characters removed.
     */
    string String::TrimStart() const
    {
        const size_type pos_start = find_first_not_of(WHITESPACE_CHARS);
        if (pos_start == npos)
        {
            return {};
        }
        return String(substr(pos_start));
    }

    /**
     * @brief Removes all the trailing white-space characters from the current string.
     *
     * @returns A new string with all the trailing white-space characters removed.
     */
    string String::TrimEnd() const
    {
        const size_type pos_end = find_last_not_of(WHITESPACE_CHARS);
        if (pos_end == npos)
        {
            return {};
        }
        return String(substr(0, pos_end + 1));
    }

    /**
     * @brief Removes all the leading and trailing white-space characters from the current string.
     *
     * @returns A new string with all the leading and trailing white-space characters removed.
     */
    string String::Trim() const
    {
        return TrimStart().TrimEnd();
    }

    /**
     * @brief Converts all characters in the string to lowercase according to the character
     * conversion rules defined by the currently installed C locale.
     *
     * In the default "C" locale, the following lowercase letters abcdefghijklmnopqrstuvwxyz
     * are replaced with respective lowercase letters ABCDEFGHIJKLMNOPQRSTUVWXYZ.
     *
     * @return A new string with all characters converted to lowercase.
     */
    string String::ToLower_Ascii7() const
    {
        String str = *this;
        std::transform(str.begin(), str.end(), str.begin(), [](const unsigned char c)
        {
            return static_cast<unsigned char>(tolower(c));
        });
        return str;
    }

    /**
     * @brief Converts all characters in the string to uppercase according to the character
     * conversion rules defined by the currently installed C locale.
     *
     * In the default "C" locale, the following uppercase letters abcdefghijklmnopqrstuvwxyz
     * are replaced with respective uppercase letters ABCDEFGHIJKLMNOPQRSTUVWXYZ.
     *
     * @return A new string with all characters converted to uppercase.
     */
    string String::ToUpper_Ascii7() const
    {
        String str = *this;
        std::transform(str.begin(), str.end(), str.begin(), [](const unsigned char c)
        {
            return static_cast<unsigned char>(toupper(c));
        });
        return str;
    }
}

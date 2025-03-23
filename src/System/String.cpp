#include "String.hpp"

#include <algorithm>  // std::transform
#include <cctype>     // std::tolower, std::toupper, std::isxdigit
#include <stdexcept>


namespace ext::System
{
    // Initialize the static constants

    const char String::TAB{'\t'};
    const char String::NEWLINE{'\n'};
    const char String::VERTICAL_TAB{'\v'};
    const char String::FORM_FEED{'\f'};
    const char String::CARRIAGE_RETURN{'\r'};
    const char String::SPACE{' '};
    const char *String::WHITESPACE_CHARS{" \t\n\v\f\r"};

    // Implementation of the extended methods

    /**
     * @brief Removes all the leading white-space characters from the current string.
     * 
     * @returns A new string with all the leading white-space characters removed.
     */
    String String::TrimStart() const
    {
        return String{TrimStart(*this)};
    }

    /**
     * @brief Removes all the trailing white-space characters from the current string.
     *
     * @returns A new string with all the trailing white-space characters removed.
     */
    String String::TrimEnd() const
    {
        return String{TrimEnd(*this)};
    }

    /**
     * @brief Removes all the leading and trailing white-space characters from the current string.
     *
     * @returns A new string with all the leading and trailing white-space characters removed.
     */
    String String::Trim() const
    {
        return String{Trim(*this)};
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
    String String::ToLower_Ascii7() const
    {
        return String{ToLower_Ascii7(*this)};
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
    String String::ToUpper_Ascii7() const
    {
        return String{ToUpper_Ascii7(*this)};
    }

    /**
     * @brief Determines whether the string is a hexadecimal number.
     *
     * @return True if the string is a hexadecimal number; otherwise, false.
     */
    bool String::isHex() const
    {
        return isHex(*this);
    }

    /**
     * @brief Removes all the leading white-space characters from the text.
     *
     * @param text The text to trim.
     * @return A new string with all the leading white-space characters removed.
     */
    std::string String::TrimStart(const std::string& text)
    {
        const size_type pos_start = text.find_first_not_of(WHITESPACE_CHARS);
        if (pos_start == std::string::npos)
        {
            return {};
        }
        return text.substr(pos_start);
    }

    /**
     * @brief Removes all the trailing white-space characters from the text.
     *
     * @param text The text to trim.
     * @return A new string with all the trailing white-space characters removed.
     */
    std::string String::TrimEnd(const std::string& text)
    {
        const size_type pos_end = text.find_last_not_of(WHITESPACE_CHARS);
        if (pos_end == std::string::npos)
        {
            return {};
        }
        return text.substr(0, pos_end + 1);
    }

    /**
     * @brief Removes all the leading and trailing white-space characters from the text.
     *
     * @param text The text to trim.
     * @return A new string with all the leading and trailing white-space characters removed.
     */
    std::string String::Trim(std::string text)
    {
        text = TrimStart(text);
        return TrimEnd(text);
    }

    /**
     * @brief Converts all characters in the text to lowercase according to the character
     * conversion rules defined by the currently installed C locale.
     *
     * In the default "C" locale, the following lowercase letters abcdefghijklmnopqrstuvwxyz
     * are replaced with respective lowercase letters ABCDEFGHIJKLMNOPQRSTUVWXYZ.
     *
     * @param text The text to convert.
     * @return A new string with all characters converted to lowercase.
     */
    std::string String::ToLower_Ascii7(std::string text)
    {
        std::transform(text.begin(), text.end(), text.begin(), [](const unsigned char c)
        {
            return static_cast<unsigned char>(std::tolower(c));
        });
        return text;
    }

    /**
     * @brief Converts all characters in the text to uppercase according to the character
     * conversion rules defined by the currently installed C locale.
     *
     * In the default "C" locale, the following uppercase letters abcdefghijklmnopqrstuvwxyz
     * are replaced with respective uppercase letters ABCDEFGHIJKLMNOPQRSTUVWXYZ.
     *
     * @param text The text to convert.
     * @return A new string with all characters converted to uppercase.
     */
    std::string String::ToUpper_Ascii7(std::string text)
    {
        std::transform(text.begin(), text.end(), text.begin(), [](const unsigned char c)
        {
            return static_cast<unsigned char>(std::toupper(c));
        });
        return text;
    }

    /**
     * @brief Determines whether the string is a hexadecimal number.
     *
     * @param text The string to check.
     * @return True if the string is a hexadecimal number; otherwise, false.
     */
    bool String::isHex(const std::string& text)
    {
        return std::all_of(text.begin(), text.end(), [](const char& c)
        {
            return std::isxdigit(c);
        });
    }

    /**
     * @brief Converts a hexadecimal string to an integer.
     *
     * This function takes a string representing a hexadecimal number and converts it to an integer.
     *
     * @param textHex The hexadecimal string to convert.
     * @return The integer value of the hexadecimal string.
     * @throws std::invalid_argument if the input is not a valid hexadecimal string.
     * @throws std::out_of_range if the input is out of range for an integer.
     */
    int String::HexToInt(const std::string& textHex)
    {
        constexpr int BASE_HEX{ 16 };

        try
        {
            return std::stoi(textHex, nullptr, BASE_HEX);
        }
        catch (const std::invalid_argument&)
        {
            throw std::invalid_argument("Invalid parameter 'textHex': " + textHex);
        }
        catch (const std::out_of_range&)
        {
            throw std::out_of_range("Parameter out of range 'textHex': " + textHex);
        }
    }

} // namespace ext::System

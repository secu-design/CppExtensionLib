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

    string String::TrimStart() const
    {
        const size_type pos_start = find_first_not_of(WHITESPACE_CHARS);
        if (pos_start == npos)
        {
            return {};
        }
        return String(substr(pos_start));
    }

    string String::TrimEnd() const
    {
        const size_type pos_end = find_last_not_of(WHITESPACE_CHARS);
        if (pos_end == npos)
        {
            return {};
        }
        return String(substr(0, pos_end + 1));
    }

    string String::Trim() const
    {
        return TrimStart().TrimEnd();
    }

    string String::ToLower_Ascii7() const
    {
        String str = *this;
        std::transform(str.begin(), str.end(), str.begin(), [](const unsigned char c)
        {
            return static_cast<unsigned char>(tolower(c));
        });
        return str;
    }

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

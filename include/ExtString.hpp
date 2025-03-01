#pragma once

#include <string>

namespace ext
{
    class String : public std::string
    {
    public:
        // Inherit constructors
        using std::string::string;

        // Conversion constructors
        explicit String(const std::string& str) : std::string{str} {}

        // Extended methods
        [[nodiscard]] String TrimStart() const;
        [[nodiscard]] String TrimEnd() const;
        [[nodiscard]] String Trim() const;

        [[nodiscard]] String ToLower() const;
        [[nodiscard]] String ToUpper() const;

        // Constants
        static const char TAB;
        static const char NEWLINE;
        static const char VERTICAL_TAB;
        static const char FORM_FEED;
        static const char CARRIAGE_RETURN;
        static const char SPACE;
        static const char* WHITESPACE_CHARS;
    };

    // Alias
    using string = String;
}

#pragma once

#include <string>


namespace ext::System
{
    class String : public std::string
    {
    public:
        // Inherit constructors
        using std::string::string;

        // Conversion constructors
        explicit String(const std::string& str) : std::string{str} {}

        // Extended instance methods
        [[nodiscard]] String TrimStart() const;
        [[nodiscard]] String TrimEnd() const;
        [[nodiscard]] String Trim() const;
        [[nodiscard]] String ToLower_Ascii7() const;
        [[nodiscard]] String ToUpper_Ascii7() const;
        [[nodiscard]] bool   isHex() const;

        // Extended static methods
        [[nodiscard]] static std::string TrimStart(const std::string& text);
        [[nodiscard]] static std::string TrimEnd(const std::string& text);
        [[nodiscard]] static std::string Trim(std::string text);
        [[nodiscard]] static std::string ToLower_Ascii7(std::string text);
        [[nodiscard]] static std::string ToUpper_Ascii7(std::string text);
        [[nodiscard]] static bool        isHex(const std::string& text);

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

}   // namespace ext::System

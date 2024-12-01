#pragma once

#include <string>

namespace ext
{
    class Console final
    {
    public:
        static void Write(const char* str);
        static void Write(const std::string& str);
        static void Write(const std::wstring& str);

        static void WriteLine(const char* str);
        static void WriteLine(const std::string& str);
        static void WriteLine(const std::wstring& str);
    };

    // Alias
    using console = Console;
}

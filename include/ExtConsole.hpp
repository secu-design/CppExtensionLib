#pragma once

#include <string>


namespace ext
{
    using std::string, std::wstring;

    class ConsoleClass final
    {
    private:
        struct ErrorStream final
        {
            void Write(const char* str);
            void Write(const string& text);
            void Write(const wstring& text);
            void WriteLine(const char* str);
            void WriteLine(const string& text);
            void WriteLine(const wstring& text);
        };

        struct OutStream final
        {
            void Write(const char* text);
            void Write(const string& text);
            void Write(const wstring& text);
            void WriteLine(const char* text);
            void WriteLine(const string& text);
            void WriteLine(const wstring& text);
        };

    public:
        ErrorStream Error;
        OutStream   Out;

        void Write(const char* text);
        void Write(const string& text);
        void Write(const wstring& text);
        void WriteLine(const char* text);
        void WriteLine(const string& text);
        void WriteLine(const wstring& text);
    };

    extern ConsoleClass Console;

}   // namespace ext

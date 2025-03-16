#pragma once

#include <string>


namespace ext
{
    using std::string, std::wstring;

    struct ConsoleClass final
    {
        struct Error final
        {
            void Write(const char* str);
            void Write(const string& text);
            void Write(const wstring& text);
            void WriteLine(const char* str);
            void WriteLine(const string& text);
            void WriteLine(const wstring& text);
        } Error;

        struct Out final
        {
            void Write(const char* text);
            void Write(const string& text);
            void Write(const wstring& text);
            void WriteLine(const char* text);
            void WriteLine(const string& text);
            void WriteLine(const wstring& text);
        } Out;

        void Write(const char* text);
        void Write(const string& text);
        void Write(const wstring& text);
        void WriteLine(const char* text);
        void WriteLine(const string& text);
        void WriteLine(const wstring& text);
    };

    extern ConsoleClass Console;

}   // namespace ext

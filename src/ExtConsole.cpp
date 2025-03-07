#include <iostream>

#include "ExtConsole.hpp"


namespace ext
{
    using
        std::cout, std::cerr,
        std::wcout, std::wcerr;


    ConsoleClass Console;


    void ConsoleClass::ErrorStream::Write(const char* str)
    {
        cerr << str;
    }

    void ConsoleClass::ErrorStream::Write(const string& text)
    {
        cerr << text;
    }

    void ConsoleClass::ErrorStream::Write(const wstring& text)
    {
        wcerr << text;
    }

    void ConsoleClass::ErrorStream::WriteLine(const char* str)
    {
        cerr << str << "\n";
    }

    void ConsoleClass::ErrorStream::WriteLine(const string& text)
    {
        cerr << text << "\n";
    }

    void ConsoleClass::ErrorStream::WriteLine(const wstring& text)
    {
        wcerr << text << L"\n";
    }

    void ConsoleClass::OutStream::Write(const char* text)
    {
        cout << text;
    }

    void ConsoleClass::OutStream::Write(const string& text)
    {
        cout << text;
    }

    void ConsoleClass::OutStream::Write(const wstring& text)
    {
        wcout << text;
    }

    void ConsoleClass::OutStream::WriteLine(const char* text)
    {
        cout << text << "\n";
    }

    void ConsoleClass::OutStream::WriteLine(const string& text)
    {
        cout << text << "\n";
    }

    void ConsoleClass::OutStream::WriteLine(const wstring& text)
    {
        wcout << text << L"\n";
    }

    void ConsoleClass::Write(const char* text)
    {
        Out.Write(text);
    }

    void ConsoleClass::Write(const string& text)
    {
        Out.Write(text);
    }

    void ConsoleClass::Write(const wstring& text)
    {
        Out.Write(text);
    }

    void ConsoleClass::WriteLine(const char* text)
    {
        Out.WriteLine(text);
    }

    void ConsoleClass::WriteLine(const string& text)
    {
        Out.WriteLine(text);
    }

    void ConsoleClass::WriteLine(const wstring& text)
    {
        Out.WriteLine(text);
    }

}   // namespace ext

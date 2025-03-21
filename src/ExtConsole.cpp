#include <iostream>

#include "ExtConsole.hpp"


namespace ext::System
{
    using
        std::cout, std::cerr,
        std::wcout, std::wcerr;


    ConsoleClass Console;


    void ConsoleClass::Error::Write(const char* str)
    {
        cerr << str;
    }

    void ConsoleClass::Error::Write(const string& text)
    {
        cerr << text;
    }

    void ConsoleClass::Error::Write(const wstring& text)
    {
        wcerr << text;
    }

    void ConsoleClass::Error::WriteLine(const char* str)
    {
        cerr << str << "\n";
    }

    void ConsoleClass::Error::WriteLine(const string& text)
    {
        cerr << text << "\n";
    }

    void ConsoleClass::Error::WriteLine(const wstring& text)
    {
        wcerr << text << L"\n";
    }

    void ConsoleClass::Out::Write(const char* text)
    {
        cout << text;
    }

    void ConsoleClass::Out::Write(const string& text)
    {
        cout << text;
    }

    void ConsoleClass::Out::Write(const wstring& text)
    {
        wcout << text;
    }

    void ConsoleClass::Out::WriteLine(const char* text)
    {
        cout << text << "\n";
    }

    void ConsoleClass::Out::WriteLine(const string& text)
    {
        cout << text << "\n";
    }

    void ConsoleClass::Out::WriteLine(const wstring& text)
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

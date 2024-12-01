#include "../include/ExtConsole.hpp"

#include <iostream>
using std::cout, std::endl, std::wcout;

namespace ext
{
    void Console::Write(const char *str)
    {
        cout << str;
    }

    void Console::Write(const std::string &str)
    {
        cout << str;
    }

    void Console::Write(const std::wstring &str)
    {
        wcout << str;
    }

    void Console::WriteLine(const char *str)
    {
        cout << str << endl;
    }

    void Console::WriteLine(const std::string &str)
    {
        cout << str << endl;
    }

    void Console::WriteLine(const std::wstring &str)
    {
        wcout << str << endl;
    }
}

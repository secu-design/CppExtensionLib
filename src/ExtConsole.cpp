#include "../include/ExtConsole.hpp"

#include <iostream>
using std::cout, std::endl, std::wcout;

namespace ext
{
    /**
     * @brief Writes a C-String to the standard output stream.
     * 
     * @param str The C-String to write.
     */
    void Console::Write(const char *str)
    {
        cout << str;
    }

    /**
     * @brief Writes a std::string to the standard output stream.
     *
     * @param str The std::string to write.
     */
    void Console::Write(const std::string &str)
    {
        cout << str;
    }

    /**
     * @brief Writes a std::wstring to the standard output stream.
     *
     * @param str The std::wstring to write.
     */
    void Console::Write(const std::wstring &str)
    {
        wcout << str;
    }

    /**
     * @brief Writes a C-String to the standard output stream followed by a newline.
     *
     * @param str The C-String to write.
     */
    void Console::WriteLine(const char *str)
    {
        cout << str << endl;
    }

    /**
     * @brief Writes a std::string to the standard output stream followed by a newline.
     *
     * @param str The std::string to write.
     */
    void Console::WriteLine(const std::string &str)
    {
        cout << str << endl;
    }

    /**
     * @brief Writes a std::wstring to the standard output stream followed by a newline.
     *
     * @param str The std::wstring to write.
     */
    void Console::WriteLine(const std::wstring &str)
    {
        wcout << str << endl;
    }
}

#pragma once

#include <string>
#include <codecvt>

// _W: utf8 string to platform unicode string (wstring on Windows)

#ifdef WIN32
#define _W(string) U8ToW(string)
#else
#define _W(string)
#endif

inline std::wstring U8ToW(const char *string)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> convert;
    return convert.from_bytes(string);
}

inline std::wstring U8ToW(const std::string &string)
{
    return U8ToW(string.c_str());
}

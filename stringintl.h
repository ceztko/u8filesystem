#pragma once

#include <string>
#include <codecvt>

inline std::wstring U8ToW(const char *string)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> convert;
    return convert.from_bytes(string);
}

inline std::wstring U8ToW(const std::string &string)
{
    return U8ToW(string.c_str());
}

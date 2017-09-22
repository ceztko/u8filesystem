﻿#include "u8filesystem.h"

#ifdef WIN32

#include "stringintl.h"

using namespace std::u8filesystem;
namespace fs = std::filesystem;

path::path() { }

path::path(const path &p)
    : fs::path(p)
{
}

path::path(path &&p) noexcept
    : fs::path(std::move(p))
{
}

path::path(const fs::path &p)
    : fs::path(p)
{
}

path::path(fs::path &&p) noexcept
    : fs::path(std::move(p))
{
}

path::path(const std::string & string)
    : fs::path(_W(string))
{
}

#endif

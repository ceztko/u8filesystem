# u8filesystem

u8filesystem is a helper for the `std::filesystem` library that helps to
deal with `std::string` encoded as UTF-8. One of the current limitations
in the design of `std::filesystem` is the inability to consistently treat
`std::string` as UTF-8 encoded in every platform. According to the
[C++17] standard:

> \* char: Encoding is the native narrow encoding

This means that in Windows platform std::string will be treated as ANSI
encoded. If cross-platform code is storing UTF-8 encoded string, evey
construction of `std::filesystem::path` with strings must be guarded so
it will convert the UTF-8 string to UTF-16 in Windows. Macros can be be
used to avoid unneeded conversion in non Windows plaftorms. Also calls to
`path::string()` must be converted to `path::u8string()`. Still, the need
for this precautions is uncovenient and subjected to errors.

A proposed solution is to fully alias all classes and methods of
`std::filesystem` to another namespace, here named `std::u8filesystem`,
so the methods will always treat `std::string` as UTF-8 encoded.
Classes are inheriting their corresponding in `std::filesystem`, not
adding any field or virtual method, to offer full interoperability. Also
same names of classes and methods are kept to make it a drop-in
replacement solution.

The inner working of the helper is assuming `std::string` is UTF-8
encoded when constructing `std::u8filesystem::path` and aliasing
`path::string()` with the same semantics, as summarized in the following
snippet:

```
static std::wstring U8ToW(const char *string);

#ifdef WIN32

path::path(const std::string & path)
    : fs::path(U8ToW(path))
{
}

std::string path::string() const
{
    return filesystem::path::u8string();
}

#endif

std::wstring U8ToW(const char *string)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> convert;
    return convert.from_bytes(string);
}
```

The helper is still incomplete and currently being tested on Windows
platform only.

   [C++17]: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0218r1.html

#include <u8filesystem.h>
#include <cassert>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;
namespace u8fs = std::u8filesystem;

fs::path foo()
{
    return fs::path(L"test.txt");
}

int main()
{
    // Test constructors and assignments with
    fs::path path1(L"test");
    u8fs::path u8path1(foo());
    u8fs::path u8path2(path1);
    u8path2 = path1;
    u8path2 = foo();

    // Test creation of directory with UNICODE characters
    u8fs::path u8path3(u8"Dirname_òàèùì");
    fs::path path2(u8"Dirname_òàèùì");
    fs::path path3("Dirname_òàèùì");

    u8fs::create_directory(u8path3);
    assert(u8fs::exists(u8path3));
    assert(fs::exists(u8path3));
    assert(fs::exists(path3));
    assert(!fs::exists(path2));
}

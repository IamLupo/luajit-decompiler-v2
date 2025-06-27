#ifndef _CHAR_UNSIGNED
#error Default char is not unsigned!
#endif

#pragma comment(linker, "/stack:268435456")
#pragma comment(lib, "shlwapi.lib")

#include <string>

constexpr char PROGRAM_NAME[] = "LuaJIT Decompiler v2";
constexpr uint64_t DOUBLE_SIGN = 0x8000000000000000;
constexpr uint64_t DOUBLE_EXPONENT = 0x7FF0000000000000;
constexpr uint64_t DOUBLE_FRACTION = 0x000FFFFFFFFFFFFF;
constexpr uint64_t DOUBLE_SPECIAL = DOUBLE_EXPONENT;
constexpr uint64_t DOUBLE_NEGATIVE_ZERO = DOUBLE_SIGN;

void print(const std::string& message);
//std::string input();
void print_progress_bar(const double& progress = 0, const double& total = 100);
void erase_progress_bar();



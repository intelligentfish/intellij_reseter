#include "XString.h"
#include <cstdarg>

// ¸ñÊ½»¯×Ö·û´®
std::wstring& sprintf(std::wstring& input,
					 int maxLen,
					 const wchar_t* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	int size = vswprintf(&input.at(0), input.capacity(), fmt, args);
	va_end(args);
	return input;
}
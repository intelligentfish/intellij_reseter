#ifndef __XSTRING_H__
#define __XSTRING_H__

#include <vector>
#include <string>

// ¸ñÊ½»¯×Ö·û´®
std::wstring& sprintf(std::wstring& input,
					  int maxLen,
					  const wchar_t* fmt, ...);

// ×Ö·û´®·Ö¸î
template<typename TCHAR>
static std::vector<std::basic_string<TCHAR>> stringSplit(const std::basic_string<TCHAR>& input,
														 const TCHAR ch,
														 std::vector<std::basic_string<TCHAR>>& output) {
	int start = 0;
	for (int end = input.find(ch, start); std::basic_string<TCHAR>::npos != end;) {
		output.push_back(input.substr(start, end - start));
		start = end + 1;
		end = input.find(ch, start);
	}
	output.push_back(input.substr(start));
	return output;
}

#endif

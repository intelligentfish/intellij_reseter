#include "DeletedRecord.h"
#include "XString.h"
#include <windows.h>
#include <fstream>

DeletedRecord::DeletedRecord(const std::wstring& evalKeyPath,
			  const std::wstring& otherXMLPath,
			  const std::wstring& regKey) :
evalKeyPath(evalKeyPath), otherXMLPath(otherXMLPath), regKey(regKey) {}

std::map<std::wstring, DeletedRecord>& DeletedRecord::fromDataFile(std::map<std::wstring, DeletedRecord>& m,
																   const std::wstring& dataFile) {
	std::wstring path(1<<12, L'\0');
	DWORD dwSize = GetCurrentDirectory(path.capacity(), &path.at(0));
	if (dwSize < path.capacity()) {
		path.resize(dwSize);
		path += L"\\" + dataFile;
		std::wifstream fs(path.c_str(), std::ios_base::in);
		std::wstring line;
		for (;fs;) {
			line.clear();
			std::getline(fs, line);
			if (line.empty()) continue;

			std::vector<std::wstring> vec;
			stringSplit(line, L'|', vec);
			m.insert(std::pair<std::wstring, DeletedRecord>(vec[2], DeletedRecord(vec[0], vec[1], vec[2])));
		}
	}
	return m;
}

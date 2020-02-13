#include <windows.h>
#include "MessageDialog.h"
#include "XString.h"
#include "DeletedRecord.h"

// 入口方法
int APIENTRY wWinMain(HINSTANCE hInstance,
					  HINSTANCE hPrevInstance,
					  LPWSTR lpCmdLine,
					  int nShow) {
	HKEY hKey = NULL;
	LSTATUS st = RegOpenKeyEx(HKEY_CURRENT_USER,  L"Software\\JavaSoft\\Prefs\\jetbrains", 0, KEY_READ, &hKey);
	do {
		if (ERROR_SUCCESS != st) {
			MessageDialog::err(NULL, L"错误", L"RegOpenKeyExW");
			break;
		}
		
		// 获取需要删除的键名
		std::map<std::wstring, DeletedRecord> recordMap;
		DeletedRecord::fromDataFile(recordMap, L"data.txt");

		// 遍历
		std::wstring keyBuf(1<<12, L'\0');
		std::wstring line(512, L'\0');
		for (int i = 0; ; i++) {
			DWORD keyNameSize = keyBuf.capacity();
			st = RegEnumKeyEx(hKey, i, &keyBuf.at(0), &keyNameSize, NULL, NULL, NULL, NULL);
			if (ERROR_NO_MORE_ITEMS == st) break;
			if (ERROR_SUCCESS != st) {
				MessageDialog::err(NULL, L"错误", L"RegEnumKeyEx");
				break;
			}
			std::wstring wchKeyName(keyBuf.c_str(), keyNameSize);
			std::map<std::wstring, DeletedRecord>::iterator it = recordMap.find(wchKeyName);
			if (recordMap.end() != it) {
				// 删除键
				st = RegDeleteTree(hKey, wchKeyName.c_str());
				MessageDialog::info(NULL, L"删除注册表", sprintf(line, 128, L"删除键: %s，结果: %d", wchKeyName.c_str(), st).c_str());
				MessageDialog::info(NULL, L"删除试用Key", 
					sprintf(line, 128, L"%s，结果: %s", it->second.evalKeyPath.c_str(), TRUE == DeleteFileW(it->second.evalKeyPath.c_str()) ? L"true" : L"false").c_str());
				MessageDialog::info(NULL, L"删除试用XML", 
					sprintf(line, 128, L"%s，结果: %s", it->second.otherXMLPath.c_str(), TRUE == DeleteFileW(it->second.otherXMLPath.c_str()) ? L"true" : L"false").c_str());
			}
		}
	} while(false);
	if (hKey) RegCloseKey(hKey);
	return 0;
}
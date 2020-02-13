#ifndef __DELETED_RECORD_H__
#define __DELETED_RECORD_H__

#include <string>
#include <map>

// ��ȡ��Ҫɾ����ע����
struct DeletedRecord {
	std::wstring evalKeyPath;
	std::wstring otherXMLPath;
	std::wstring regKey;

	static std::map<std::wstring, DeletedRecord>& fromDataFile(std::map<std::wstring, DeletedRecord>& m, 
		const std::wstring& dataFile);

	DeletedRecord(const std::wstring& evalKeyPath,
		const std::wstring& otherXMLPath,
		const std::wstring& regKey);
};

#endif

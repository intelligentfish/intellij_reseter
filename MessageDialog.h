#ifndef __MESSAGE_DIALOG_H__
#define __MESSAGE_DIALOG_H__

#include <windows.h>

// ��Ϣ�Ի���
struct MessageDialog {
	// ��ʾ
	static void info(HWND hWnd, const wchar_t* title, const wchar_t* text);
	// ����
	static void err(HWND hWnd, const wchar_t* title, const wchar_t* text);
private:
	// ��ʾ
	static void show(HWND hWnd, const wchar_t* title, const wchar_t* text, INT btnAndIcon);
};

#endif

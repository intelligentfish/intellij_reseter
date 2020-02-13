#ifndef __MESSAGE_DIALOG_H__
#define __MESSAGE_DIALOG_H__

#include <windows.h>

// 消息对话框
struct MessageDialog {
	// 提示
	static void info(HWND hWnd, const wchar_t* title, const wchar_t* text);
	// 错误
	static void err(HWND hWnd, const wchar_t* title, const wchar_t* text);
private:
	// 显示
	static void show(HWND hWnd, const wchar_t* title, const wchar_t* text, INT btnAndIcon);
};

#endif

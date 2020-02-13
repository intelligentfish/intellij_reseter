#include "MessageDialog.h"

void MessageDialog::info(HWND hWnd, 
						const wchar_t* title,
						const wchar_t* text) {
	MessageDialog::show(hWnd, title, text, MB_OK | MB_ICONINFORMATION);
}

void MessageDialog::err(HWND hWnd,
					   const wchar_t* title,
					   const wchar_t* text) {
	MessageDialog::show(hWnd, title, text, MB_OK | MB_ICONERROR);
}

void MessageDialog::show(HWND hWnd,
						const wchar_t* title,
						const wchar_t* text,
						INT btnAndIcon) {
	MessageBox(hWnd, text, title, btnAndIcon);
}
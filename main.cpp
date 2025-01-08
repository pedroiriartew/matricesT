#include <windows.h>
#include "OpenGL_Wrap.h"

LRESULT CALLBACK DummyWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProcA(hwnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK FinalWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
		    PostQuitMessage(0);
		    return 0;
	}
	return DefWindowProcA(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	//Registering the Window Class
	const char* CLASS_NAME = "Transform prototype";

	WNDCLASS wc = { }; 

	wc.lpfnWndProc = FinalWindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.style = CS_OWNDC;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowExA(0, CLASS_NAME,"Transform Matrix", WS_OVERLAPPEDWINDOW,
							 CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
							 NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		return 0;
	}

	ShowWindow(hwnd, nShowCmd);

	//OpenGLW::InitializeOpenGLContext(hwnd);

	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
}

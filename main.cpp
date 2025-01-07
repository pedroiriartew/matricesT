#include <windows.h>
#include <winuser.h>
#include "OpenGL_Wrap.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.style = CS_OWNDC; //this little shit removes the X and all of th usual buttons in a window 

	RegisterClass(&wc);

	HWND hwnd = CreateWindowExA(0, CLASS_NAME,"Transform Matrix", wc.style,
							 CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
							 NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		return 0;
	}

	ShowWindow(hwnd, nShowCmd);

	OpenGLW::InitializeOpenGLContext(hwnd);

	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
}

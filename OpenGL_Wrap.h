#include <windows.h>
#include <gl/GL.h>

namespace OpenGLW
{
	void InitializeContext(HWND hwnd);
	void InitializeDummy(HWND hwnd, HDC hDC);
	bool LoadFunctions();
}

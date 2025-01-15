#include "OpenGL_Wrap.h"

using namespace OpenGLW;

void OpenGLW::InitializeDummy(HWND hwnd, HDC hDC)
	{
	//Pixel format attributes (Windows SDK documentation)
	PIXELFORMATDESCRIPTOR pfd =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
			PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
			32,                   // Colordepth of the framebuffer.
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,                   // Number of bits for the depthbuffer
			8,                    // Number of bits for the stencilbuffer
			0,                    // Number of Aux buffers in the framebuffer.
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

	//Choose the Pixel format most similar to the descriptor
	int pixelFormatNumber = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, pixelFormatNumber, &pfd);

	HGLRC hGLRenderingContext = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hGLRenderingContext);

	//Loadfunctions
	

	//specs pc "messagebox get OpenGL version" 
	MessageBoxA(0,(char*)glGetString(GL_VERSION), "OPENGL VERSION",0);

	//Remove current context
	wglMakeCurrent(hDC, NULL);
	wglDeleteContext(hGLRenderingContext);
}

void OpenGLW::InitializeContext(HWND hwnd)
{
	// DeviceContext (DC) 
	HDC hDeviceContext = GetDC(hwnd); //h? handle

	//Pixel format attributes (Windows SDK documentation)
	PIXELFORMATDESCRIPTOR pfd =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
			PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
			32,                   // Colordepth of the framebuffer.
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,                   // Number of bits for the depthbuffer
			8,                    // Number of bits for the stencilbuffer
			0,                    // Number of Aux buffers in the framebuffer.
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

	//Choose the Pixel format most similar to the descriptor
	int pixelFormatNumber = ChoosePixelFormat(hDeviceContext, &pfd);
	SetPixelFormat(hDeviceContext, pixelFormatNumber, &pfd);

	//Creating the OpenGL context and making it current
	HGLRC hGLRenderingContext = wglCreateContext(hDeviceContext);
	wglMakeCurrent(hDeviceContext, hGLRenderingContext);
}

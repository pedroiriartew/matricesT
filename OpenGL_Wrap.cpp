#include <windows.h>
#include <gl/GL.h>

namespace OpenGLW
{
	void InitializeOpenGLContext(HWND hwnd)
	{
		// DeviceContext (DC) 
		HDC hDeviceContext =GetDC(hwnd); //h? handle

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
}

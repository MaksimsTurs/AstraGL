#include "./AGLCore.h"

LRESULT CALLBACK window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
  	case WM_CLOSE: 
    	PostQuitMessage(0);
      return 0;
    case WM_DESTROY:
      return 0;
  }
  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void AGL_create_window(HWND* window, AGL_CString title, AGL_UInt16 width, AGL_UInt16 height) {
  WNDCLASS window_class = {0};
	HINSTANCE window_instance = {0};

	window_instance = GetModuleHandle(NULL);
  
	window_class.lpfnWndProc = window_proc;
  window_class.hInstance = window_instance;
  window_class.lpszClassName = title;
	window_class.hCursor = LoadCursor(0, IDC_ARROW);

  if(!RegisterClass(&window_class)) {
		ASTRAGL_LOG(ASTRAGL_LOG_ERROR, "Can not register a window!", NULL);
	}

  *window = CreateWindowEx(
  	0, 
		window_class.lpszClassName, 
		window_class.lpszClassName, 
		WS_OVERLAPPEDWINDOW,
  	CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		width, 
		height,
    NULL, 
		NULL, 
		window_instance, 
		NULL
	);

  if(window == NULL) {
    ASTRAGL_LOG(ASTRAGL_LOG_ERROR, "Can not create a window!", NULL);
  }

  if(ShowWindow(*window, SW_SHOW)) {
    ASTRAGL_LOG(ASTRAGL_LOG_ERROR, "Can now show a window!", NULL);
	}
}

void AGL_create_context(HWND window) {
	PIXELFORMATDESCRIPTOR pixel_format = {0};
	HGLRC opengl_context = {0};
	HDC device_context = {0};

	AGL_Int8 choosed_pixel_format = 0;
	pixel_format.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixel_format.nVersion = 1;
	pixel_format.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pixel_format.iPixelType = PFD_TYPE_RGBA;

	device_context = GetDC(window);
	choosed_pixel_format = ChoosePixelFormat(device_context, &pixel_format);
	if(!SetPixelFormat(device_context, choosed_pixel_format, &pixel_format)) {
		ASTRAGL_LOG(ASTRAGL_LOG_ERROR, "Can not set pixel format!", NULL);
	}

	opengl_context = wglCreateContext(device_context);
	if(!wglMakeCurrent(device_context, opengl_context)) {
		ASTRAGL_LOG(ASTRAGL_LOG_ERROR, "Can not make context current!", NULL);
	}
}

AGL_Boolean AGL_event_loop(MSG event_message) {
	AGL_Boolean recieved_message = GetMessage(&event_message, NULL, 0, 0);
	
	TranslateMessage(&event_message);
  DispatchMessage(&event_message);

	return recieved_message;
}

void AGL_clear_buffer() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void AGL_swap_buffer(HWND window) {
	SwapBuffers(GetDC(window));
}
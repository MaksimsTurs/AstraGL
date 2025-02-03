#include "./AGLBinding.h"

PFNGLGENBUFFERSPROC glGenBuffers;
PFNGLBINDBUFFERPROC glBindBuffer;
PFNGLBUFFERDATAPROC glBufferData;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
PFNGLCREATEPROGRAMPROC glCreateProgram;
PFNGLATTACHSHADERPROC glAttachShader;
PFNGLDELETESHADERPROC glDeleteShader;
PFNGLLINKPROGRAMPROC glLinkProgram;
PFNGLVALIDATEPROGRAMPROC glValidateProgram;
PFNGLCREATESHADERPROC glCreateShader;
PFNGLSHADERSOURCEPROC glShaderSource;
PFNGLCOMPILESHADERPROC glCompileShader;
PFNGLGETSHADERIVPROC glGetShaderiv;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
PFNGLUSEPROGRAMPROC glUseProgram;

void AGL_bind_openGL() {
	glGenBuffers = (void*)wglGetProcAddress("glGenBuffers");
	glBindBuffer = (void*)wglGetProcAddress("glBindBuffer");
	glBufferData = (void*)wglGetProcAddress("glBufferData");
	glEnableVertexAttribArray = (void*)wglGetProcAddress("glEnableVertexAttribArray");
	glVertexAttribPointer = (void*)wglGetProcAddress("glVertexAttribPointer");
	glCreateProgram = (void*)wglGetProcAddress("glCreateProgram");
	glAttachShader = (void*)wglGetProcAddress("glAttachShader");
	glDeleteShader = (void*)wglGetProcAddress("glDeleteShader");
	glLinkProgram = (void*)wglGetProcAddress("glLinkProgram");
	glValidateProgram = (void*)wglGetProcAddress("glValidateProgram");
	glCreateShader = (void*)wglGetProcAddress("glCreateShader");
	glShaderSource = (void*)wglGetProcAddress("glShaderSource");
	glCompileShader = (void*)wglGetProcAddress("glCompileShader");
	glGetShaderiv = (void*)wglGetProcAddress("glGetShaderiv");
	glGetShaderInfoLog = (void*)wglGetProcAddress("glGetShaderInfoLog");
	glUseProgram = (void*)wglGetProcAddress("glUseProgram");
}
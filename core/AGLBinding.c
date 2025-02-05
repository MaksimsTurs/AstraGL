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
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
PFNGLUNIFORM1FPROC glUniform1f;
PFNGLUNIFORM1IPROC glUniform1i;
PFNGLUNIFORM2FPROC glUniform2f;
PFNGLUNIFORM3FPROC glUniform3f;
PFNGLUNIFORM4FPROC glUniform4f;
PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
PFNGLDELETEBUFFERSPROC glDeleteBuffers;
PFNGLACTIVETEXTUREPROC glActiveTexture;

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
	glUniform1f = (void*)wglGetProcAddress("glUniform1f");
	glUniform1i = (void*)wglGetProcAddress("glUniform1i");
	glGetUniformLocation = (void*)wglGetProcAddress("glGetUniformLocation");
	glUniform2f = (void*)wglGetProcAddress("glUniform2f");
	glUniform3f = (void*)wglGetProcAddress("glUniform3f");
	glUniform4f = (void*)wglGetProcAddress("glUniform4f");
	glGenVertexArrays = (void*)wglGetProcAddress("glGenVertexArrays");
	glBindVertexArray = (void*)wglGetProcAddress("glBindVertexArray");
	glDeleteBuffers = (void*)wglGetProcAddress("glDeleteBuffers");
	glActiveTexture = (void*)wglGetProcAddress("glActiveTexture");

	wglSwapIntervalEXT = (void*)wglGetProcAddress("wglSwapIntervalEXT");
}
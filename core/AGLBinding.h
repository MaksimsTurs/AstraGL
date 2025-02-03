#pragma once

#include "./AGLCore.h"

#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4
#define GL_VERTEX_SHADER 0x8B31
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_COMPILE_STATUS 0x8B81
#define GL_INFO_LOG_LENGTH 0x8B84

typedef ptrdiff_t GLsizeiptr;
typedef char GLchar;

typedef void (APIENTRY* PFNGLGENBUFFERSPROC) (GLsizei, GLuint*);
typedef void (APIENTRY* PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRY* PFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const void* data, GLenum usage);
typedef void (APIENTRY* PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
typedef void (APIENTRY* PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRY* PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRY* PFNGLDELETESHADERPROC) (GLuint shader);
typedef void (APIENTRY* PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void (APIENTRY* PFNGLVALIDATEPROGRAMPROC) (GLuint program);
typedef void (APIENTRY* PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar *const* string, const GLint* length);
typedef void (APIENTRY* PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef void (APIENTRY* PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint* param);
typedef void (APIENTRY* PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (APIENTRY* PFNGLUSEPROGRAMPROC) (GLuint program);
typedef GLuint (APIENTRY* PFNGLCREATEPROGRAMPROC) (void);
typedef GLuint (APIENTRY* PFNGLCREATESHADERPROC) (GLenum type);

extern PFNGLGENBUFFERSPROC glGenBuffers;
extern PFNGLBINDBUFFERPROC glBindBuffer;
extern PFNGLBUFFERDATAPROC glBufferData;
extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
extern PFNGLCREATEPROGRAMPROC glCreateProgram;
extern PFNGLATTACHSHADERPROC glAttachShader;
extern PFNGLDELETESHADERPROC glDeleteShader;
extern PFNGLLINKPROGRAMPROC glLinkProgram;
extern PFNGLVALIDATEPROGRAMPROC glValidateProgram;
extern PFNGLCREATESHADERPROC glCreateShader;
extern PFNGLSHADERSOURCEPROC glShaderSource;
extern PFNGLCOMPILESHADERPROC glCompileShader;
extern PFNGLGETSHADERIVPROC glGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
extern PFNGLUSEPROGRAMPROC glUseProgram;

void AGL_bind_openGL();

#pragma once

#include <windows.h>
#include <stdio.h>
#include <GL/gl.h>

#define AGL_LOG_INFO    "INFO"
#define AGL_LOG_ERROR   "ERROR"
#define AGL_LOG_WARNING "WARNING"

#define AGL_TRUE 1
#define AGL_FALSE 0

#ifndef AGL_DEV_MODE
	#define AGL_LOG(LEVEL, FORMAT, ...) printf("[" LEVEL "]: " FORMAT "\n", __VA_ARGS__)
#else
	#define AGL_LOG(LEVEL, FORMAT, ...)
#endif

//Boolean
typedef char AGL_Boolean;

//Strings
typedef const char* AGL_CString;
typedef char* AGL_VString;

//8 Bit integer
typedef char AGL_Int8;
typedef signed char AGL_SInt8;
typedef unsigned char AGL_UInt8;

//16 Bit integers
typedef short AGL_Int16;
typedef signed short AGL_SInt16;
typedef unsigned short AGL_UInt16;

//32 Bit integers
typedef int AGL_Int32;
typedef signed int AGL_SInt32;
typedef unsigned int AGL_UInt32;

//64 Bit integers
typedef long AGL_Int64;
typedef signed long AGL_SInt64;
typedef unsigned long AGL_UInt64;

//128 Bit integers
typedef long long AGL_Int128;
typedef signed long long AGL_SInt128;
typedef unsigned long long AGL_UInt128;

//16 Bit floats
typedef float AGL_Float16;

//32 Bit floats
typedef double AGL_Float32;

//64 Bit floats
typedef long double AGL_Float64;

typedef struct AGL_RGBA {
	AGL_Float16 r;
	AGL_Float16 g;
	AGL_Float16 b;
	AGL_Float16 a;
} UI_RGBA;

typedef struct AGL_Position {
	AGL_Float16 x;
	AGL_Float16 y;
	AGL_Int8 z;
} UI_Position;

typedef struct AGL_Size {
	AGL_Float16 width;
	AGL_Float16 height;
	AGL_Float16 scale;
} UI_Size;

void AGL_window_create(HWND* window, AGL_CString title, AGL_UInt16 width, AGL_UInt16 height);
void AGL_openGL_context_create(HWND window);

AGL_Boolean AGL_programm_loop(MSG event_message);

#include "./AGLBinding.h"
#include "./AGLBuffer.h"
#include "./AGLRenderer.h"
#include "./AGLShader.h"
#include "./AGLTexture.h"
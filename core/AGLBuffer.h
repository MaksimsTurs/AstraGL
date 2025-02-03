#pragma once

#include "./AGLCore.h"

typedef struct AGL_VBuffer {
	AGL_UInt32 id;
} AGL_VBuffer;

typedef struct AGL_VBuffer_Array {
	AGL_UInt32 id;
} AGL_VBuffer_Array;

typedef struct AGL_IBuffer {
	AGL_UInt32 id;
	AGL_UInt32 count;
} AGL_IBuffer;

void AGL_vbuffer_create(AGL_VBuffer* buffer, AGL_Float16* positions, AGL_UInt16 size);
void AGL_vbuffer_array_create(AGL_VBuffer_Array* buffer);
void AGL_ibuffer_create(AGL_IBuffer* buffer, AGL_UInt16* data, AGL_Int16 size);

void AGL_buffer_bind(AGL_UInt16 type, AGL_UInt32 id);
void AGL_buffer_unbind(AGL_UInt16 type);
void AGL_buffer_delete(AGL_UInt32 id);
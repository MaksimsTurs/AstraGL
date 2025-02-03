#pragma once

#include "./AGLCore.h"

typedef struct AGL_VBuffer {
	AGL_UInt32 id;
	AGL_UInt16 size;
	AGL_Float16* positions;
} AGL_VBuffer;

typedef struct AGL_IBuffer {
	AGL_UInt32 id;
	AGL_UInt16 size;
	AGL_UInt16* data;	
} AGL_IBuffer;

void AGL_init_vbuffer(AGL_VBuffer* buffer, AGL_Float16* positions, AGL_UInt16 size, AGL_UInt8 verticies_size);
// void UI_index_buffer_init(UI_IBuffer* buffer, UI_U16Int* data, UI_U16Int size);

// void UI_buffer_bind(UI_U16Int type, UI_U32Int id);
// void UI_buffer_unbind(UI_U16Int type);
// void UI_buffer_delete(UI_U32Int id);
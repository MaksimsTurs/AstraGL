#pragma once

#include "./AGLCore.h"

typedef struct AGL_Texture {
	AGL_UInt32 id;
	AGL_CString path;
	AGL_Int32 width;
	AGL_Int32 height;
	AGL_Int32 BBP;
} AGL_Texture;

void AGL_texture_create(AGL_Texture* texture, AGL_CString path);

void AGL_texture_bind(AGL_UInt16 slot, AGL_UInt32 id);
void AGL_texture_unbind();
void AGL_texture_delete(AGL_UInt32 id);
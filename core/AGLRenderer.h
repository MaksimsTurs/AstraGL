#pragma once

#include "./AGLCore.h"

// void AGL_render_component(AGL_VBuffer_Array* vbuffer_array, AGL_IBuffer* ibuffer, AGL_UInt32 shader_id);

void AGL_swap_buffer(HWND window);
void AGL_swap_buffer_interval(AGL_UInt8 interval);
void AGL_clear_buffer();
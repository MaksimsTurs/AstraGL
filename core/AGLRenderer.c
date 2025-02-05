#include "./AGLRenderer.h"

void AGL_render_component(AGL_VBuffer_Array* vbuffer_array, AGL_IBuffer* ibuffer, AGL_UInt32 shader_id) {
	AGL_buffer_bind(GL_ELEMENT_ARRAY_BUFFER, ibuffer->id);
	AGL_shader_bind(shader_id);
	AGL_buffer_bind(0, vbuffer_array->id);

	glDrawElements(GL_TRIANGLES, ibuffer->count, GL_UNSIGNED_SHORT, NULL);
}

void AGL_clear_buffer() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void AGL_swap_buffer(HWND window) {
	SwapBuffers(GetDC(window));
}

void AGL_swap_buffer_interval(AGL_UInt8 interval) {
	wglSwapIntervalEXT(interval);
}
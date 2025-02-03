#include "./core/AGLCore.h"

int main(void) {
	HWND window = {0};
	MSG event_message = {0};

	AGL_create_window(&window, "OpenGL UI library AstraGL", 650, 450);
	AGL_create_context(window);
	AGL_bind_openGL();

	AGL_VBuffer button_vbuffer = {0};
	AGL_UInt32 base_shader_id = 0;
	AGL_Float16 button_vbuffer_verticies[6] = {
		-0.5f, -0.5f,
		0.0f, 0.5f, 
		0.5f, -0.5f,
	};

	AGL_init_vbuffer(&button_vbuffer, button_vbuffer_verticies, sizeof(AGL_Float16) * sizeof(button_vbuffer_verticies), sizeof(AGL_Float16) * 2);
	base_shader_id = AGL_shader_create("./core/shaders/base.vertex.glsl", "./core/shaders/base.fragment.glsl");
	AGL_shader_bind(base_shader_id);

	while(AGL_event_loop(event_message)) {
		AGL_clear_buffer();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		AGL_swap_buffer(window);
	}

	return 0;
}
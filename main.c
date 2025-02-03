#include "./core/AGLCore.h"

int main(void) {
	HWND window = {0};
	MSG event_message = {0};

	AGL_window_create(&window, "OpenGL UI library AstraGL", 650, 450);
	AGL_openGL_context_create(window);
	AGL_bind_openGL();
	AGL_swap_buffer_interval(1);

	AGL_VBuffer button_vbuffer = {0};
	AGL_IBuffer button_ibuffer = {0};
	AGL_UInt16 button_ibuffeer_indecies[6] = {
		0, 1, 2,
		2, 3, 0
	};
	AGL_Float16 button_vbuffer_verticies[8] = {
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.5f, 0.5f,
		-0.5f, 0.5f
	};
	AGL_UInt32 button_shader = 0;

	AGL_vbuffer_create(&button_vbuffer, button_vbuffer_verticies, sizeof(AGL_Float16) * sizeof(button_vbuffer_verticies));
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(AGL_Float16) * 2, 0);
	glEnableVertexAttribArray(0);

	AGL_ibuffer_create(&button_ibuffer, button_ibuffeer_indecies, (sizeof(button_ibuffeer_indecies) / sizeof(AGL_UInt16)));

	AGL_Float16 r = 1.0f;	
	AGL_Float16 inc = 0.0f;

	button_shader = AGL_shader_create("./core/shaders/base.vertex.glsl", "./core/shaders/base.fragment.glsl");
	AGL_shader_bind(button_shader);
	AGL_shader_set_uniform4f(button_shader, "u_base", r, 0.0f, 0.0f, 1.0f);

	while(AGL_event_loop(event_message)) {
		AGL_clear_buffer();

		AGL_shader_set_uniform4f(button_shader, "u_base", r, 0.0f, 0.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, button_ibuffer.count, GL_UNSIGNED_SHORT, NULL);

		if(r >= 1.0f) {
			inc -= 0.05f;
		} else if(r < 0.0f) {
			inc += 0.05f;
		}

		r += inc;

		AGL_swap_buffer(window);
	}
	return 0;
}
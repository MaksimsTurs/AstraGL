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
	AGL_VBuffer_Array vbuffer_array = {0};
	AGL_Texture button_texture = {0};
	AGL_UInt16 button_ibuffeer_indecies[6] = {
		0, 1, 2,
		2, 3, 0
	};
	AGL_Float16 button_vbuffer_verticies[] = {
		//Position      Texture
		-0.5f, -0.5f,   0.0f, 0.0f,
		 0.5f, -0.5f,   1.0f, 0.0f,
		 0.5f,  0.5f,   1.0f, 1.0f,
		-0.5f,  0.5f,   1.0f, 0.0f
	};
	AGL_UInt32 button_shader = 0;

	AGL_vbuffer_array_create(&vbuffer_array);

	AGL_vbuffer_create(&button_vbuffer, button_vbuffer_verticies, sizeof(AGL_Float16) * sizeof(button_vbuffer_verticies) + 10);
	AGL_buffer_bind(GL_ARRAY_BUFFER, button_vbuffer.id);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(AGL_Float16) * 8, 0);
	// glEnableVertexAttribArray(1);
	// glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(AGL_Float16) * 4, (const void*)(2 * sizeof(AGL_Float16)));

	// AGL_ibuffer_create(&button_ibuffer, button_ibuffeer_indecies, (sizeof(button_ibuffeer_indecies) / sizeof(AGL_UInt16)));
	// AGL_buffer_bind(GL_ELEMENT_ARRAY_BUFFER, button_ibuffer.id);
	
	button_shader = AGL_shader_create("./core/shaders/base.vertex.glsl", "./core/shaders/base.fragment.glsl");
	
	AGL_texture_create(&button_texture, "./core/textures/wp_1.png");
	AGL_texture_bind(1, button_texture.id);
	
	AGL_shader_set_uniform1i(button_shader, "u_tex", 1);
	AGL_shader_bind(button_shader);
	
	while(AGL_programm_loop(event_message)) {
		AGL_clear_buffer();

		AGL_buffer_bind(0, vbuffer_array.id);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, NULL);
		// AGL_render_component(&vbuffer_array, &button_ibuffer, button_shader);

		AGL_swap_buffer(window);
	}
	
	return 0;
}
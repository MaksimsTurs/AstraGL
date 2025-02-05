#version 330 core

out vec4 color;

in vec2 out_tex_coor;

uniform sampler2D u_tex;

void main() {
	vec4 tex_color = texture(u_tex, out_tex_coor);
	// color = tex_color;
	color = vec4(1.0, 0.0, 0.0, 1.0);
}
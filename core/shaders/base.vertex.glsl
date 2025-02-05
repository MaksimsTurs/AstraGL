#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 tex_coor; 

out vec2 out_tex_coor;

void main() {
	gl_Position = position;
	out_tex_coor = tex_coor;
}
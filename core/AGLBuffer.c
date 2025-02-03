#include "./AGLBuffer.h"

void AGL_vbuffer_create(AGL_VBuffer* buffer, AGL_Float16* positions, AGL_UInt16 size) {
	glGenBuffers(1, &buffer->id);
	glBindBuffer(GL_ARRAY_BUFFER, buffer->id);
	glBufferData(GL_ARRAY_BUFFER, size, positions, GL_STATIC_DRAW);
}

void AGL_ibuffer_create(AGL_IBuffer* buffer, AGL_UInt16* data, AGL_Int16 count) {
	buffer->count = count;

	glGenBuffers(1, &buffer->id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(AGL_UInt16), data, GL_STATIC_DRAW);
}

void AGL_vbuffer_array_create(AGL_VBuffer_Array* buffer) {
	glGenVertexArrays(1, &buffer->id);
	glBindVertexArray(buffer->id);
}

void AGL_buffer_bind(AGL_UInt16 type, AGL_UInt32 id) {
	switch(type) {
		case GL_ELEMENT_ARRAY_BUFFER:
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
		break;
		case GL_ARRAY_BUFFER:
			glBindBuffer(GL_ARRAY_BUFFER, id);
		break;
		default:
			glBindVertexArray(id);
		break;
	}
}

void AGL_buffer_unbind(AGL_UInt16 type) {
	switch(type) {
		case GL_ELEMENT_ARRAY_BUFFER:
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		break;
		case GL_ARRAY_BUFFER:
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		break;
		default:
			glBindVertexArray(0);
		break;
	}
}

void AGL_buffer_delete(AGL_UInt32 id) {
	glDeleteBuffers(1, &id);
}
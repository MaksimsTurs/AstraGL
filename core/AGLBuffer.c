#include "./AGLBuffer.h"

void AGL_init_vbuffer(AGL_VBuffer* buffer, AGL_Float16* positions, AGL_UInt16 size, AGL_UInt8 verticies_size) {
	buffer->id = 0;
	buffer->size = size;
	buffer->positions = positions;

	glGenBuffers(1, &buffer->id);
	glBindBuffer(GL_ARRAY_BUFFER, buffer->id);
	glBufferData(GL_ARRAY_BUFFER, size, positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, verticies_size, 0);
}

// void UI_index_buffer_init(UI_IBuffer* buffer, UI_U16Int* data, UI_U16Int size) {
// 	buffer->id = 0;
// 	buffer->size = size;
// 	buffer->data = data;

// 	glGenBuffers(1, &buffer->id);
// 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->id);
// 	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
// }

// void UI_buffer_bind(UI_U16Int type, UI_U32Int id) {
// 	switch(type) {
// 		case GL_ELEMENT_ARRAY_BUFFER:
// 			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
// 		break;
// 		case GL_ARRAY_BUFFER:
// 			glBindBuffer(GL_ARRAY_BUFFER, id);
// 			glEnableVertexAttribArray(0);
// 		break;
// 	}
// }

// void UI_buffer_unbind(UI_U16Int type) {
// 	switch(type) {
// 		case GL_ELEMENT_ARRAY_BUFFER:
// 			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
// 		break;
// 		case GL_ARRAY_BUFFER:
// 			glBindBuffer(GL_ARRAY_BUFFER, 0);
// 		break;
// 	}
// }

// void UI_buffer_delete(UI_U32Int id) {
// 	glDeleteBuffers(1, &id);
// }
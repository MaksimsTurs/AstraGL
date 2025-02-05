#include "./AGLTexture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "./libs/AGL_stbi_image.h"

void AGL_texture_create(AGL_Texture* texture, AGL_CString path) {
	texture->path = path;

	stbi_set_flip_vertically_on_load(1);
	unsigned char* texture_buffer = stbi_load(path, &texture->width, &texture->height, &texture->BBP, 4);

	glGenTextures(1, &texture->id);
	glBindTexture(GL_TEXTURE_2D, texture->id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture_buffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if(texture_buffer) {
		stbi_image_free(texture_buffer);
	}
}

void AGL_texture_delete(AGL_UInt32 id) {
	glDeleteTextures(1, &id);
}

void AGL_texture_bind(AGL_UInt16 slot, AGL_UInt32 id) {
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, id);
}

void AGL_texture_unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}
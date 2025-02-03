#include "./AGLShader.h"

AGL_UInt32 AGL_shader_create(AGL_CString vertex_shader_path, AGL_CString fragment_shader_path) {
	AGL_UInt32 programm_id = 0;
	AGL_UInt32 shader_id = 0;
	AGL_VString shader_source = NULL;

	programm_id = glCreateProgram();

	if(vertex_shader_path != NULL) {
		ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Process %s", vertex_shader_path);
		ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Get source", NULL);
		shader_source = AGL_get_shader_source_from_path(vertex_shader_path);
		ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Compile source", NULL);
		shader_id = AGL_shader_compile(shader_source, GL_VERTEX_SHADER);
		ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Attach shader", NULL);
		glAttachShader(programm_id, shader_id);
		ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Free shader source", NULL);
		free(shader_source);
		ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Delete shader", NULL);
		glDeleteShader(shader_id);
	}

	if(fragment_shader_path != NULL) {
		ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Process %s", fragment_shader_path);
		ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Get source", NULL);
		shader_source = AGL_get_shader_source_from_path(fragment_shader_path);
		ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Compile source", NULL);
		shader_id = AGL_shader_compile(shader_source, GL_FRAGMENT_SHADER);
		ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Attach shader", NULL);
		glAttachShader(programm_id, shader_id);
		ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Free shader source", NULL);
		free(shader_source);
		ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Delete shader", NULL);
		glDeleteShader(shader_id);
	}

	ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Linking shader programm %i", programm_id);
	glLinkProgram(programm_id);
	ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Validate programm", NULL);
	glValidateProgram(programm_id);

	return programm_id;
}

AGL_UInt32 AGL_shader_compile(AGL_CString shader_source, AGL_Int32 shader_type) {
	AGL_UInt32 shader_id = 0;
	
	int compilation_result = 0;
	int compilation_error_length = 0;
	char* compilation_error_message = NULL;

	shader_id = glCreateShader(shader_type);
	glShaderSource(shader_id, 1, &shader_source, NULL);
	glCompileShader(shader_id);

	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compilation_result);
	if(compilation_result == GL_FALSE) {
		glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &compilation_error_length);

		compilation_error_message = (char*)malloc(compilation_error_length);

		glGetShaderInfoLog(shader_id, compilation_error_length, &compilation_error_length, compilation_error_message);
		glDeleteShader(shader_id);
	
		ASTRAGL_LOG(ASTRAGL_LOG_ERROR, "Error in %s source \n%s", shader_type == GL_VERTEX_SHADER ? "Vertex" : "Fragment", compilation_error_message);

		return 0;
	}

	return shader_id;
}

AGL_VString AGL_get_shader_source_from_path(AGL_CString shader_path) {
	FILE* shader_file = fopen(shader_path, "rb");
	AGL_VString shader_source = NULL;
	unsigned long long shader_source_length = 0;
	if(shader_file == NULL) {
		ASTRAGL_LOG(ASTRAGL_LOG_ERROR, "Can not open shader source %s", shader_path);
		return NULL;
	}

	fseek(shader_file, 0, SEEK_END); 
	shader_source_length = ftell(shader_file);
	fseek(shader_file, 0, SEEK_SET); 
	ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Shader source length %lli", shader_source_length);

	shader_source = (AGL_VString)malloc(shader_source_length);
	if(shader_source == NULL) {
		ASTRAGL_LOG(ASTRAGL_LOG_ERROR, "Can no alloc memory for glsl source", NULL);
		return NULL;
	}

	fread(shader_source, 1, shader_source_length, shader_file);
	fclose(shader_file);

	shader_source[shader_source_length] = '\0';
	ASTRAGL_LOG(ASTRAGL_LOG_INFO, "Shader source\n%s", shader_source);

	return shader_source;
}

void AGL_shader_bind(AGL_UInt32 shader_id) {
	glUseProgram(shader_id);
}

void AGL_shader_undind() {
	glUseProgram(0);
}

void AGL_shader_delete(AGL_UInt32 shader_id) {
	glDeleteShader(shader_id);
}

// void UI_shader_set_uniform1f(UI_U32Int shader_id, UI_CString uniform_name, UI_16Float f1) {
// 	glUniform1f(glGetUniformLocation(shader_id, uniform_name), f1);
// }

// void UI_shader_set_uniform2f(UI_U32Int shader_id, UI_CString uniform_name, UI_16Float f1, UI_16Float f2) {
// 	glUniform2f(glGetUniformLocation(shader_id, uniform_name), f1, f2);
// }

// void UI_shader_set_uniform3f(UI_U32Int shader_id, UI_CString uniform_name, UI_16Float f1, UI_16Float f2, UI_16Float f3) {
// 	glUniform3f(glGetUniformLocation(shader_id, uniform_name), f1, f2, f3);
// }

// void UI_shader_set_uniform4f(UI_U32Int shader_id, UI_CString uniform_name, UI_16Float f1, UI_16Float f2, UI_16Float f3, UI_16Float f4) {
// 	glUniform4f(glGetUniformLocation(shader_id, uniform_name), f1, f2, f3, f4);
// }

// void UI_shader_set_uniform1i(UI_U32Int shader_id, UI_CString uniform_name, UI_U8Int type) {
// 	glUniform1i(glGetUniformLocation(shader_id, uniform_name), type);
// }
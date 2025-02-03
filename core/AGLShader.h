#pragma once

#include "./AGLCore.h"

#include <string.h>

AGL_UInt32 AGL_shader_create(AGL_CString vertex_shader_path, AGL_CString fragment_shader_path);
AGL_UInt32 AGL_shader_compile(AGL_CString shader_source, AGL_Int32 shader_type);
AGL_VString AGL_get_shader_source_from_path(AGL_CString shader_path);

void AGL_shader_bind(AGL_UInt32 shader_id);
void AGL_shader_undind();
void AGL_shader_delete(AGL_UInt32 shader_id);

void AGL_shader_set_uniform1f(AGL_UInt32 shader_id, AGL_CString uniform_name, AGL_Float16 uniform_value);
void AGL_shader_set_uniform1i(AGL_UInt32 shader_id, AGL_CString uniform_name, AGL_UInt8 uniform_value);
void AGL_shader_set_uniform2f(AGL_UInt32 shader_id, AGL_CString uniform_name, AGL_Float16 f1, AGL_Float16 f2);
void AGL_shader_set_uniform3f(AGL_UInt32 shader_id, AGL_CString uniform_name, AGL_Float16 f1, AGL_Float16 f2, AGL_Float16 f3);
void AGL_shader_set_uniform4f(AGL_UInt32 shader_id, AGL_CString uniform_name, AGL_Float16 f1, AGL_Float16 f2, AGL_Float16 f3, AGL_Float16 f4);
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "..\core\raw_model.h"

class Shader
{
public:
	std::string vertex_shader_source;
	std::string fragment_shader_source;
	static std::vector<int> shader_id, program_id;
	unsigned int vertex_shader_id, fragment_shader_id;
	unsigned int p_id;

public:

	Shader();

	~Shader();

	void uploadVertexShader(const std::string& fileName);

	void uploadFragmentShader(const std::string& fileName);

	void compileShader(const GLuint shader_type, const int shader_count);

	void uploadAndCompileShader(rend_eng::RawModel& raw, std::string& vertex_shader_file, std::string& fragment_shader_file);
	
	unsigned int createProgram();

	void useProgram();

};


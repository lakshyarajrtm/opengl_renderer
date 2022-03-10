#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Shader
{
public:
	std::string shader_source;
	static std::vector<int> shader_id, program_id;
	unsigned int s_id;

public:

	Shader();

	~Shader();

	void uploadShader(const std::string fileName);

	void compileShader(const GLuint shader_type, const int shader_count);
	
	static unsigned int createProgram(const Shader vertexShader, const Shader fragmentShader);
};


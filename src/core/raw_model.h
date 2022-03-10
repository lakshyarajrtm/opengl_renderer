#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "..\utility\shader.h"

namespace rend_eng 
{
	struct Position
	{
		float x, y, z;
	};

	struct Color
	{
		float x, y, z, w;
	};

	struct Vertex
	{
		Position position;
		Color color;
	};

	struct Index
	{
		int x, y, z;
	};


	class RawModel 
	{
	private:

		int vaoID;
		int vertexCount;
		Shader vertex, fragment;

	public:
		unsigned int program_id;


	public:

		RawModel() noexcept;

		RawModel(RawModel&) noexcept;

		RawModel(RawModel&&) noexcept;

		RawModel(int vaoID, int vertexCount);

		int getVaoID();

		int getVertextCount();

		void uploadAndCompileShader(std::string& vertex_shader_file, std::string& fragment_shader_file);

		RawModel& operator=(RawModel&);

		RawModel& operator=(RawModel&&);
	};


}
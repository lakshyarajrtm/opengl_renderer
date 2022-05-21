#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>


namespace rend_eng 
{
	struct vec3 
	{
		float x, y, z;
	};

	struct vec4
	{
		float x, y, z, w;
	};

	struct Vertex
	{
		vec3 position;
		vec4 color;
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

	public:
		unsigned int p_id;
		

	public:

		RawModel() noexcept;

		RawModel(RawModel&) noexcept;

		RawModel(RawModel&&) noexcept;

		RawModel(int vaoID, int vertexCount);

		int getVaoID();

		int getVertextCount();

		RawModel& operator=(RawModel&);

		RawModel& operator=(RawModel&&);
	};


}
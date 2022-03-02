#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace rend_eng 
{
	struct Vertex
	{
		float x, y, z;
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

		RawModel() noexcept;

		RawModel(RawModel&) noexcept;

		RawModel(RawModel&&) noexcept;

		RawModel(int vaoID, int vertexCount);

		int getVaoID();

		int getVertextCount();

	};


}
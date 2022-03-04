#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "raw_model.h"


namespace rend_eng 
{
	class Renderer 
	{
	public:
		Renderer();
		~Renderer();

		Renderer(Renderer&) = delete;
		Renderer(Renderer&&) = delete;

		void prepare();

		void render(RawModel model, int primitive);
	};
}


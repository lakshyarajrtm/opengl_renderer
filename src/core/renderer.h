#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "raw_model.h"
#include "glm/vec3.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


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

		void render_model(RawModel& model, int primitive);

		void transform(RawModel& model, Position translate, float rotate, float scale, int axis);
		// static void drawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);

		void transform3d(RawModel& model);
	};
}


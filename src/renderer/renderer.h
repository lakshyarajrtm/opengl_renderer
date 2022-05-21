#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "..\core\raw_model.h"
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

		void transform(RawModel& model, vec3 translate, float rotate, float scale, int axis);

		void transform3d(RawModel& model, float rotation_angle, vec3 axis, vec3 translation_vec, float prespective_angle);
	};
}


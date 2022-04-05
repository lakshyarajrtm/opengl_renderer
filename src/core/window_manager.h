#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "renderer.h"
#include "loader.h"
#include "raw_model.h"
#include "event_manager.h"

#include "..\utility\shader.h"
#include "glm/vec3.hpp"


namespace rend_eng
{
	class WindowManager
	{
	public:
		int width, height;
		GLFWwindow* window;

	public:
		WindowManager();

		~WindowManager();

		int init(int width, int height);

		int update();
	};
}


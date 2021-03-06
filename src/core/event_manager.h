#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

constexpr int KEY_COUNT = 256;
constexpr int MOUSE_KEY_COUNT = 3;

namespace rend_eng
{
	class EventManager
	{
	public:

		bool keys[KEY_COUNT];
		bool mouse_keys[MOUSE_KEY_COUNT];
		int scan_code = 0;
		int action = 0;
		int key_mods = 0;
		int mouse_mods = 0;
		double xPos = 0.0f, yPos = 0.0f;

	public:

		static EventManager* createEventManager();

		EventManager(EventManager&) = delete;

		EventManager(EventManager&&) = delete;

		~EventManager();

	private:

		EventManager() noexcept;

	};

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

}



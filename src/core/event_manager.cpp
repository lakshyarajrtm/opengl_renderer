#include "event_manager.h"

std::unique_ptr<rend_eng::EventManager> event_manager(rend_eng::EventManager::createEventManager());

rend_eng::EventManager* rend_eng::EventManager::createEventManager() 
{
	static int count = 0;
	if (count == 0) {
		count++;
		return new EventManager();
	}
}

rend_eng::EventManager::EventManager() noexcept
{
	for (int i = 0; i < KEY_COUNT; i++) 
		keys[i] = false;
}


rend_eng::EventManager::~EventManager() 
{
	std::cout << "Deleting event_manager";
}

void rend_eng::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
	if (action == GLFW_PRESS)
		event_manager->keys[key] = true;
	if (action == GLFW_RELEASE)
		event_manager->keys[key] = false;

	event_manager->scan_code = scancode;
	event_manager->action = action;
	event_manager->key_mods = mods;
}

void rend_eng::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) 
{
	event_manager->xPos = xpos;
	event_manager->yPos = ypos;
}

void rend_eng::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) 
{
	if (action == GLFW_PRESS)
		event_manager->mouse_keys[button] = true;
	if (action == GLFW_RELEASE)
		event_manager->mouse_keys[button] = false;

	event_manager->mouse_mods = mods;
}



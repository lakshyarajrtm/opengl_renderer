#include "event_manager.h"

rend_eng::EventManager* rend_eng::EventManager::event_manager = nullptr;

void rend_eng::EventManager::createEventManager() 
{
	static int count = 0;

	if (count == 0)
		event_manager = new EventManager();
	count++;

}

rend_eng::EventManager::EventManager() 
{

	for (int i = 0; i < KEY_COUNT; i++) 
	{
		keys[i] = false;
	}

}

rend_eng::EventManager::~EventManager() 
{

	delete event_manager;
	event_manager = nullptr;
}


void rend_eng::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
	if (action == GLFW_PRESS)
		EventManager::event_manager->keys[key] = true;
	if (action == GLFW_RELEASE)
		EventManager::event_manager->keys[key] = false;

	EventManager::event_manager->scan_code = scancode;
	EventManager::event_manager->action = action;
	EventManager::event_manager->key_mods = mods;
}

void rend_eng::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) 
{
	EventManager::event_manager->xPos = xpos;
	EventManager::event_manager->yPos = ypos;
}

void rend_eng::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) 
{
	if (action == GLFW_PRESS)
		EventManager::event_manager->mouse_keys[button] = true;
	if (action == GLFW_RELEASE)
		EventManager::event_manager->mouse_keys[button] = false;

	EventManager::event_manager->mouse_mods = mods;
}



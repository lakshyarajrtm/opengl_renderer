#pragma once
#include "renderer.h"
class Camera
{
public:
	rend_eng::vec3 camera_pos;

	rend_eng::vec3 camera_target;
	rend_eng::vec3 camera_direction;

	rend_eng::vec3 camera_up;
	

};


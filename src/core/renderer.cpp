#include "renderer.h"

rend_eng::Renderer::Renderer() {}

rend_eng::Renderer::~Renderer() {}

void rend_eng::Renderer::prepare() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void rend_eng::Renderer::render_model(RawModel& model, int primitive) 
{
	glBindVertexArray(model.getVaoID());
	glEnableVertexArrayAttrib(model.getVaoID(), 0);
	glEnableVertexArrayAttrib(model.getVaoID(), 1);
	glDrawElements(primitive, model.getVertextCount(), GL_UNSIGNED_INT, 0);
}

void rend_eng::Renderer::transform(RawModel& model, Position translate, float rotate, float scale, int axis)
{
	// choose axis 0 for rotation in x axis, 1 for y axis and 2 for z axis
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, glm::vec3(translate.x, translate.y, translate.z));
	trans = glm::scale(trans, glm::vec3(scale, scale, scale));
	glm::vec3 rotation_axis;
	switch (axis)
	{
	case 0:
		rotation_axis = glm::vec3(1.0f, 0.0f, 0.0f);
		break;
	case 1:
		rotation_axis = glm::vec3(0.0f, 1.0f, 0.0f);
		break;
	case 2:
		rotation_axis = glm::vec3(0.0f, 0.0f, 1.0f);
		break;
	}
	trans = glm::rotate(trans, rotate, rotation_axis);

	unsigned int transformLoc = glGetUniformLocation(model.p_id, "transform");

	/*
		* this function must be in the renderer loop
		glGetUniformLocation returns an integer that represents the location of a specific uniform variable within a
		program object.name must be a null terminated string that contains no white space.name must be an active uniform
		variable name in program that is not a structure, an array of structures, or a subcomponent of a vector or
		a matrix.This function returns - 1 if name does not correspond to an active uniform variable in program or
		if name starts with the reserved prefix "gl_".
	 */
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}


void rend_eng::Renderer::transform3d(RawModel& model)
{
	glm::mat4 mod        = glm::mat4(1.0f);
	glm::mat4 view       = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);


	mod = glm::rotate(mod, (float)glfwGetTime() * glm::radians(-95.0f), glm::vec3(1.0f, 0.0f, 1.0f));
	// note that we're translating the scene in the reverse direction of where we want to move
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 800.0f, 0.1f, 100.0f);


	unsigned int model_loc = glGetUniformLocation(model.p_id, "model");
	unsigned int view_loc = glGetUniformLocation(model.p_id, "view");
	unsigned int projection_loc = glGetUniformLocation(model.p_id, "projection");

	glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(mod));
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection));

}
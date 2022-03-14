#include "renderer.h"

rend_eng::Renderer::Renderer() {}

rend_eng::Renderer::~Renderer() {}

void rend_eng::Renderer::prepare() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void rend_eng::Renderer::render(RawModel& model, int primitive) 
{
	glUseProgram(model.program_id);
	glBindVertexArray(model.getVaoID());
	glEnableVertexArrayAttrib(model.getVaoID(), 0);
	glEnableVertexArrayAttrib(model.getVaoID(), 1);
	glDrawElements(primitive, model.getVertextCount(), GL_UNSIGNED_INT, 0);
}

#include "renderer.h"

void rend_eng::Renderer::prepare() 
{
	glClearColor(0, 0.5, 1, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
}

void rend_eng::Renderer::render(RawModel model) 
{
	glBindVertexArray(model.getVaoID());
	glEnableVertexArrayAttrib(model.getVaoID(), 0);
	glDrawArrays(GL_TRIANGLES, 0, model.getVertextCount());
}
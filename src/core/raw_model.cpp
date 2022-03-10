#pragma once
#include "raw_model.h"

rend_eng::RawModel::RawModel() noexcept : vaoID(0), vertexCount(0) { }

rend_eng::RawModel::RawModel(RawModel&& raw) noexcept 
{
	this->vaoID = raw.getVaoID();
	this->vertexCount = raw.getVertextCount();
	raw.vaoID = 0;
	raw.vertexCount = 0;
}

rend_eng::RawModel::RawModel(RawModel& raw) noexcept 
{
	this->vaoID = raw.getVaoID();
	this->vertexCount = raw.getVertextCount();
}

rend_eng::RawModel::RawModel(int vaoID, int vertexCount)
{
	this->vaoID = vaoID;
	this->vertexCount = vertexCount;
	
}

int rend_eng::RawModel::getVaoID() 
{
	return vaoID;
}

int rend_eng::RawModel::getVertextCount() 
{
	return vertexCount;
}


rend_eng::RawModel& rend_eng::RawModel::operator=(RawModel& model)
{
	this->vaoID = model.getVaoID();
	this->vertexCount = model.getVertextCount();

	return *this;
}

rend_eng::RawModel& rend_eng::RawModel::operator=(RawModel&& model)
{
	this->vaoID = model.getVaoID();
	this->vertexCount = model.getVertextCount();
	model.vaoID = 0;
	model.vertexCount = 0;
	
	return *this;
}

void rend_eng::RawModel::uploadAndCompileShader(std::string& vertex_shader_file, std::string& fragment_shader_file)
{
	this->vertex.uploadShader(vertex_shader_file);
	this->fragment.uploadShader(fragment_shader_file);
	this->vertex.compileShader(GL_VERTEX_SHADER, 1);
	this->fragment.compileShader(GL_FRAGMENT_SHADER, 1);
	this->program_id = Shader::createProgram(vertex, fragment);
}
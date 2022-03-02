#include "loader.h"
#include "raw_model.h"


rend_eng::RawModel rend_eng::Loader::loadToVao(const std::vector<float>& positions) 
{
	int vaoID = createVao();
	storeDataInAttributeList(0, positions);
	unbindVao();

	return rend_eng::RawModel(vaoID, (positions.size() / 3) );
}

int rend_eng::Loader::createVao() 
{
	int vaoID;
	glGenVertexArrays(1, (GLuint*) &vaoID);
	glBindVertexArray(vaoID);
	vaos.push_back(vaoID);

	return vaoID;
}

void rend_eng::Loader::storeDataInAttributeList(int attributeNumber, const std::vector<float>& data) 
{
	int vboID;
	glGenBuffers(1, (GLuint*)&vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), (void*)data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, false, sizeof(float) * 3, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	vbos.push_back(vboID);
}

void rend_eng::Loader::unbindVao() 
{
	glBindVertexArray(0);
}

void rend_eng::Loader::cleanUp() 
{
	for (auto& v : vaos) {
		glDeleteVertexArrays(1, (GLuint*)&v);
	}
	for (auto& v : vbos) {
		glDeleteBuffers(1, (GLuint*)&v);
	}
}
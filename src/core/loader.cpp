#include "loader.h"
#include "raw_model.h"


rend_eng::Loader::Loader() noexcept {}

rend_eng::Loader::~Loader() {}

rend_eng::RawModel rend_eng::Loader::loadModel(const std::vector<rend_eng::Vertex>& positions,
													const std::vector <rend_eng::Index>& indices)
{
	int vaoID = createVao();
	storeDataInAttributeList(std::make_pair<int,int>(0, 1), positions, indices);
	unbindVao();
	return rend_eng::RawModel(vaoID, (indices.size() * sizeof(Index)) / sizeof(int));
}

int rend_eng::Loader::createVao() 
{
	int vaoID;
	glGenVertexArrays(1, (GLuint*) &vaoID);
	glBindVertexArray(vaoID);
	vaos.push_back(vaoID);

	return vaoID;
}

void rend_eng::Loader::storeDataInAttributeList(std::pair<int, int> attributeNumber, const std::vector<rend_eng::Vertex>& data,
														const std::vector < rend_eng::Index>& indices)
{
	int vboID;
	glGenBuffers(1, (GLuint*)&vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(Vertex), (void*)data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(attributeNumber.first, sizeof(vec3) / sizeof(float), GL_FLOAT, GL_FALSE,
														sizeof(Vertex), (void*)offsetof(Vertex, position));
	glVertexAttribPointer(attributeNumber.second, sizeof(vec4) / sizeof(float), GL_FLOAT, GL_FALSE,
														sizeof(Vertex), (void*) offsetof(Vertex, color));
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	int eboID;
	glGenBuffers(1, (GLuint*) &eboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * (sizeof(int) * 3), (void*) indices.data(), GL_STATIC_DRAW);
	vbos.push_back(vboID);
}

void rend_eng::Loader::unbindVao() 
{
	glBindVertexArray(0);
}

void rend_eng::Loader::cleanUp() 
{
	for (auto& v : vaos) 
		glDeleteVertexArrays(1, (GLuint*)&v);
	
	for (auto& v : vbos) 
		glDeleteBuffers(1, (GLuint*)&v);
	
}
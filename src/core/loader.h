#pragma once
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "raw_model.h"
#include "glm/vec3.hpp"

namespace rend_eng 
{

	class Loader 
	{
	private:
		std::vector<int> vaos, vbos;

	public:
		Loader() noexcept;

		Loader(Loader&) = delete;
		
		Loader(Loader&&) = delete;

		~Loader();

		RawModel loadModel(const std::vector<rend_eng::Vertex>& positions,
			const std::vector < rend_eng::Index>& indices);

		int createVao();

		void storeDataInAttributeList(std::pair<int, int> attributeNumber, const std::vector<rend_eng::Vertex>& data, 
													const std::vector<rend_eng::Index>& indices);

		void unbindVao();

		void cleanUp();
	};
}
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

		RawModel loadModel(const std::vector<rend_eng::Position>& positions,
			const std::vector < rend_eng::Index>& indices);

		int createVao();

		void storeDataInAttributeList(int attributeNumber, const std::vector<rend_eng::Position>& data, 
													const std::vector<rend_eng::Index>& indices);

		void unbindVao();

		void cleanUp();
	};
}
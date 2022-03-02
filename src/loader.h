#pragma once
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "raw_model.h"

namespace rend_eng 
{

	class Loader 
	{
	private:
		std::vector<int> vaos, vbos;

	public:
		RawModel loadToVao(const std::vector<float>& positions);

	private:
		int createVao();

		void storeDataInAttributeList(int attributeNumber, const std::vector<float>& data);

		void unbindVao();

		void cleanUp();
	};
}
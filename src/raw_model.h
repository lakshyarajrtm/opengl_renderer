#pragma once

namespace rend_eng 
{
	class RawModel 
	{
	private:

		int vaoID;
		int vertexCount;

	public:

		RawModel() noexcept;

		RawModel(RawModel&) noexcept;

		RawModel(RawModel&&) noexcept;

		RawModel(int vaoID, int vertexCount);

		int getVaoID();

		int getVertextCount();
	};


}
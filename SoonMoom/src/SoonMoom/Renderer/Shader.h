#pragma once
#include "smpch.h"
struct ShaderProgaramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};


namespace SoonMoom
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();


		void Bind()const;
		void UnBind()const;


	private:
		uint32_t m_RendererID = 0;
	};

}
#pragma once
#include "smpch.h"
#include "RendererAPI.h"
#include "RenderCommand.h"
namespace SoonMoom
{
	class Renderer
	{
	public:
		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

		inline static  RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	};


}
#include "smpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "OpenGLVertexArray.h"

namespace SoonMoom
{
	SoonMoom::VertexArray* VertexArray::Creat()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
		{
			SM_CORE_ASSERT(false, "RendererAPI : None is currently not supported !");
			SM_CORE_ERROR("RendererAPI : None is currently not supported !");
			return nullptr;
		}
		case RendererAPI::API::OpenGL:
		{
			SM_CORE_INFO("RendererAPI : OpenGL !");
			return new OpenGLVertexArray();
		}
		default:
		{
			SM_CORE_ASSERT(false, "UnKnown RendererAPI !");
			SM_CORE_ERROR("UnKnown RendererAPI !");
			break;
		}
		}
		return nullptr;
	}

}
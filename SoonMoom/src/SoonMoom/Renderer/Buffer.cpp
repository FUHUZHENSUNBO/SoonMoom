#include "smpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "OpenGLBuffer.h"

#include "glad/glad.h"

#if SM_PLATFORM_WINDOWS_DRX
#include "Platform/Direct3D/Direct3DBuffer.h"
#endif


namespace SoonMoom
{

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch(Renderer::GetAPI())
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
			return new OpenGLVertexBuffer(vertices, size);
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


	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
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
			return new OpenGLIndexBuffer(indices, count);
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




	uint32_t BufferElement::SwitchToGLType()const
	{
		switch (m_DataType)
		{
		case ShaderDataType::Float:
			return GL_FLOAT;
		case ShaderDataType::Float2:
			return GL_FLOAT;
		case ShaderDataType::Float3:
			return GL_FLOAT;
		case ShaderDataType::Float4:
			return GL_FLOAT;
		case ShaderDataType::Mat3:
			return GL_FLOAT;
		case ShaderDataType::Mat4:
			return GL_FLOAT;
		case ShaderDataType::Int:
			return GL_INT;
		case ShaderDataType::Int2:
			return GL_INT;
		case ShaderDataType::Int3:
			return GL_INT;
		case ShaderDataType::Int4:
			return GL_INT;
		case ShaderDataType::Bool:
			return GL_INT;
		default:
			break;
		}
		SM_CORE_ASSERT(false, "Unknowned ShaderDataType  !");
		return GL_NONE;
	}

}
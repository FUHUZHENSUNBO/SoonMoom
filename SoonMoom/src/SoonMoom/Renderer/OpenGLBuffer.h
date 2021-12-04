#pragma once
#include "smpch.h"
#include "Buffer.h"

namespace SoonMoom
{
	class OpenGLVertexBuffer:public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		~OpenGLVertexBuffer();
		virtual void Bind() override;
		virtual	void UnBind() override;


		virtual const BufferLayout& GetLayout()const override
		{
			return m_BufferLayout; 
		}

		virtual void SetLayout(const BufferLayout& layout) override 
		{
			m_BufferLayout = layout;
		}

	private:
		uint32_t m_RendererID = 0;
		BufferLayout m_BufferLayout;
	};



	class OpenGLIndexBuffer :public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer();
		virtual void Bind() override;
		virtual void UnBind() override;
		inline uint32_t GetCount() { return m_count; }
	private:
		uint32_t m_RendererID = 0;
		uint32_t m_count = 0;
	};


}
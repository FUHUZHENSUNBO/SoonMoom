#include "smpch.h"
#include "OpenGLVertexArray.h"
#include "glad/glad.h"



namespace SoonMoom
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{

	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::UnBind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) const
	{
		SM_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().empty(), "vertexBuffer Layout is empty !");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		const auto& layout = vertexBuffer->GetLayout();
		uint32_t index = 0;
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				element.GetComponentCount(),
				element.SwitchToGLType(),
				element.m_Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.m_Offset
			);
			++index;
		}

	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();
		m_IndexBufferBox = indexBuffer;
	}

}
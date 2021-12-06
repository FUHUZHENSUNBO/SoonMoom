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
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);

		m_IndexBuffer->Bind();
	}

	void OpenGLVertexArray::UnBind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
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
		m_VertexBufferBox.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();
		m_IndexBuffer = indexBuffer;
	}

	const std::vector<std::shared_ptr<SoonMoom::VertexBuffer>>& OpenGLVertexArray::GetVertexBuffers() const
	{
		return m_VertexBufferBox;
	}

	const std::shared_ptr<SoonMoom::IndexBuffer>& OpenGLVertexArray::GetIndexBuffers() const
	{
		return m_IndexBuffer;
	}

}
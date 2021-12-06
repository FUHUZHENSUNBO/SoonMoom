#pragma once
#include "smpch.h"
#include "VertexArray.h"
#include "SoonMoom/Renderer/Buffer.h"
//////////////////////////////////////
//不能在常成员函数中修改成员变量的值//
/////////////////////////////////////
namespace SoonMoom
{
	class OpenGLVertexArray:public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind()const override;
		virtual void UnBind()const override;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)  override;


		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers()const override;
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffers()const override;
	private:
		uint32_t m_RendererID;
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBufferBox;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;

	};



}
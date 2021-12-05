#pragma once
#include "VertexArray.h"
namespace SoonMoom
{
	class OpenGLVertexArray:public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind()const override;
		virtual void UnBind()const override;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)const override;//�����ڳ���Ա�������޸ĳ�Ա������ֵ
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)  override;
	private:
		std::shared_ptr<IndexBuffer> m_IndexBufferBox;
		unsigned int m_RendererID;
	};



}
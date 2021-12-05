#pragma once
#include "smpch.h"
#include "Buffer.h"
namespace SoonMoom
{
	class VertexArray
	{
	public:

		virtual ~VertexArray() = default;

		virtual void Bind()const = 0;
		virtual void UnBind()const = 0;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer)const = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& buffer) = 0;

		static VertexArray* Creat();

	};
}
#pragma once
#if 1
#include "smpch.h"



namespace SoonMoom
{
	enum class ShaderDataType
	{
		None = 0,
		Float,
		Float2,
		Float3,
		Float4,
		Mat3,
		Mat4,
		Int,
		Int2,
		Int3,
		Int4,
		Bool
	};

	static uint32_t ShaderDataTypeSize(const ShaderDataType& type)
	{
		switch (type)
		{
		case ShaderDataType::None:
			return 0;
		case ShaderDataType::Float:
			return 4;
		case ShaderDataType::Float2:
			return 8;
		case ShaderDataType::Float3:
			return 12;
		case ShaderDataType::Float4:
			return 16;
		case ShaderDataType::Mat3:
			return 36;
		case ShaderDataType::Mat4:
			return 64;
		case ShaderDataType::Int:
			return 4;
		case ShaderDataType::Int2:
			return 8;
		case ShaderDataType::Int3:
			return 12;
		case ShaderDataType::Int4:
			return 16;
		case ShaderDataType::Bool:
			return 1;
		default:
			break;
		}
		SM_CORE_ASSERT(false, "Unknowned ShaderDataType  !");
		return 0;
	}

	class BufferElement
	{
	public:
		std::string m_Name;
		ShaderDataType m_DataType;
		uint32_t m_Offset;
		uint32_t m_Size;
		bool m_Normalized;
		BufferElement(const std::string& name, const ShaderDataType& type,bool normalized=false)
			:m_Name(name), m_DataType(type), m_Size(ShaderDataTypeSize(type)), m_Offset(0),m_Normalized(normalized)
		{
			//
		}
		uint32_t GetComponentCount()const
		{
			switch (m_DataType)
			{
			case ShaderDataType::Float:
				return 1;
			case ShaderDataType::Float2:
				return 2;
			case ShaderDataType::Float3:
				return 3;
			case ShaderDataType::Float4:
				return 4;
			case ShaderDataType::Mat3:
				return 9;
			case ShaderDataType::Mat4:
				return 16;
			case ShaderDataType::Int:
				return 1;
			case ShaderDataType::Int2:
				return 2;
			case ShaderDataType::Int3:
				return 3;
			case ShaderDataType::Int4:
				return 4;
			case ShaderDataType::Bool:
				return 1;
			default:
				break;
			}
			return 0;
		}
 
		uint32_t SwitchToGLType()const;
	};


	class BufferLayout
	{
	private:
		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride = 0;

	private:
		void CalculateOffsetAndStride()
		{
			uint32_t offset = 0;
			m_Stride = 0;
			for (auto& element : m_Elements)
			{
				element.m_Offset = offset;
				offset += element.m_Size;
				m_Stride += element.m_Size;
			}
		}

	public:
		BufferLayout(std::initializer_list<BufferElement> element) :m_Elements(element)
		{
			CalculateOffsetAndStride();
		}
		BufferLayout() {}
		inline const uint32_t GetStride()const{ return m_Stride; }
		inline const std::vector<BufferElement>& GetElements()const { return m_Elements; }
		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const{ return m_Elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const{ return m_Elements.end(); }

	};


	class VertexBuffer
	{
	public:

		virtual void Bind() = 0;
		virtual	void UnBind() = 0;
		virtual void SetLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& GetLayout()const = 0;
		static VertexBuffer* Create(float* vertices, uint32_t size);
	};

	class IndexBuffer
	{
	public:
		virtual void Bind() = 0;
		virtual void UnBind() = 0;
		virtual inline uint32_t GetCount() = 0;
		static IndexBuffer* Create(uint32_t* indices, uint32_t count);
	};

}
#endif
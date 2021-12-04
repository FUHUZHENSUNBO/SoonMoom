//#pragma once
//#include "smpch.h"
//
//
//
//namespace SoonMoom
//{
//	enum class ShaderDataType
//	{
//		None = 0,
//		Float,
//		Float2,
//		Float3,
//		Float4,
//		Mat3,
//		Mat4,
//		Int,
//		Int2,
//		Int3,
//		Int4,
//		Bool
//	};
//
//	static uint32_t ShaderDataTypeSize(const ShaderDataType& type)
//	{
//		switch (type)
//		{
//		case ShaderDataType::None:
//			return 0;
//		case ShaderDataType::Float:
//			return 4;
//		case ShaderDataType::Float2:
//			return 8;
//		case ShaderDataType::Float3:
//			return 12;
//		case ShaderDataType::Float4:
//			return 16;
//		case ShaderDataType::Mat3:
//			return 36;
//		case ShaderDataType::Mat4:
//			return 64;
//		case ShaderDataType::Int:
//			return 4;
//		case ShaderDataType::Int2:
//			return 8;
//		case ShaderDataType::Int3:
//			return 12;
//		case ShaderDataType::Int4:
//			return 16;
//		case ShaderDataType::Bool:
//			return 1;
//		default:
//			break;
//		}
//		SM_CORE_ASSERT(false,"Unknowned ShaderDataType  !");
//		return 0;
//	}
//
//	class BufferElement
//	{
//	private:
//		ShaderDataType m_dataType;
//		std::string m_name;
//		uint32_t m_offset;
//		uint32_t m_size;
//
//	public:
//		BufferElement(const std::string& name,const ShaderDataType& type)
//			:m_name(name), m_dataType(type), m_size(ShaderDataTypeSize(type)), m_offset(0)
//		{
//			//
//		}
//		inline void SetOffset(const uint32_t& offset) { m_offset = offset; }
//		inline const ShaderDataType& GetDataType() { return  m_dataType; }
//		inline const std::string& GetName() { return m_name; }
//		inline const uint32_t& GetSize() { return m_size; }
//		inline const uint32_t& GetOffset() { return m_offset; }
//		inline const uint32_t GetComponentCount()
//		{
//			switch (m_dataType)
//			{
//			case ShaderDataType::None:
//				return 0;
//			case ShaderDataType::Float:
//				return 4;
//			case ShaderDataType::Float2:
//				return 8;
//			case ShaderDataType::Float3:
//				return 12;
//			case ShaderDataType::Float4:
//				return 16;
//			case ShaderDataType::Mat3:
//				return 36;
//			case ShaderDataType::Mat4:
//				return 64;
//			case ShaderDataType::Int:
//				return 4;
//			case ShaderDataType::Int2:
//				return 8;
//			case ShaderDataType::Int3:
//				return 12;
//			case ShaderDataType::Int4:
//				return 16;
//			case ShaderDataType::Bool:
//				return 1;
//			default:
//				break;
//			}
//			SM_CORE_ASSERT(false, "Unknowned ShaderDataType  !");
//			return 0;
//		}
//		const unsigned int SwitchToGLType();
//
//	};
//
//
//	class BufferLayout
//	{
//	private:
//		std::vector<BufferElement> m_Elements;
//		uint32_t m_Stride = 0;
//
//	private:
//		void CalculateOffsetAndStride()
//		{
//			uint32_t offset = 0;
//			m_Stride = 0;
//			for (auto& element : m_Elements)
//			{
//				element.SetOffset(offset);
//				offset += element.GetSize();
//				m_Stride += element.GetSize();
//			}
//		}
//
//	public:
//		BufferLayout(std::initializer_list<BufferElement> element):m_Elements(element)
//		{
//			CalculateOffsetAndStride();
//		}
//		//~BufferLayout();
//		inline const std::vector<BufferElement>& GetElements()const { return m_Elements; }
//		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
//		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
//
//	};
//
//
//	class VertexBuffer
//	{
//	public:
//
//		virtual void Bind() = 0;
//		virtual	void UnBind() = 0;
//
//		virtual const BufferLayout& GetLayout()const = 0;
//		virtual void SetLayout(const BufferLayout&) = 0;
//
//
//		static VertexBuffer* Create(float* vertices,uint32_t size);
//	};
//
//	class IndexBuffer
//	{
//	public:
//		virtual void Bind()=0;
//		virtual void UnBind()=0;
//		virtual inline uint32_t GetCount() = 0;
//		static IndexBuffer* Create(uint32_t* indices, uint32_t count);
//	};
//
//}
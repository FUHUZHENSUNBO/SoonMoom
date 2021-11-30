#pragma once
#include "smpch.h"

#include "SoonMoom/Core.h"
#include "SoonMoom/Events/Event.h"


namespace SoonMoom
{
	class  Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach(){}
		virtual void OnDetach(){}
		virtual void OnUpdate(){}
		virtual void OnImGuiRender(){}
		virtual void OnEvent(Event& event){}

		inline const std::string& GetName()const{ return m_DebugName; }

		protected:
		std::string m_DebugName;
	};

}
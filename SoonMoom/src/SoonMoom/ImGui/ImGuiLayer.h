#pragma once
#include "SoonMoom/Core.h"
#include "SoonMoom/Layer.h"

#include "SoonMoom/Events/ApplicationEvent.h"
#include "SoonMoom/Events/KeyEvent.h"
#include "SoonMoom/Events/MouseEvent.h"


namespace SoonMoom {
	
	class  ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender()override;

		void Begin();
		void End();

	private:
		bool m_BlockEvents = true;
	};

}

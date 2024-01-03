#pragma once

#include "dvigatel/Layer.h"

#include "dvigatel/Events/KeyEvent.h"
#include "dvigatel/Events/MouseEvent.h"
#include "dvigatel/Events/ApplicationEvent.h"

namespace dvg {

	class DVG_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}


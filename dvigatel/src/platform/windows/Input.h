#pragma once

#include "dvigatel/Input.h"

namespace dvg {
	class WindowsInput : public Input {
		protected:
			virtual bool IsKeyPressedImpl(int keycode) override;
			virtual bool IsMouseButtonPressedImpl(int button) override;

			virtual float GetMouseXImpl() override;
			virtual float GetMouseYImpl() override;
	};

}

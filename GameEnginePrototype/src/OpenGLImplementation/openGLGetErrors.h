#pragma once
#include "RenderAPI/GetError.h"


namespace Proto {
	class openGLErrors : public Error {
	public:
		openGLErrors() = default;

		virtual void GetErrors() override;
	};
}

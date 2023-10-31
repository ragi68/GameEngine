#pragma once
#include "Proto/EntryCore.h"
#include "PrecompiledHeaders.h"
#include "rendercontext.h"

namespace Proto {
	class Direct3D : public rendercontext {
	public:
		virtual void Init() override;
		virtual void SwapBuffer() override; 
		virtual void SwapChain() = 0; 
	};
}
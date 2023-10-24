#pragma once

#include "Proto/EntryCore.h"
#include "Proto/EventSystem/EventHeader.h"


namespace Proto{
	class PROTO_API LayerClass
	{
	public:
		LayerClass(const std::string& name = "Layer");
		virtual ~LayerClass();
		 //exectable functions for layers on the stack. 
		virtual void OnStack(){}
		virtual void OnPop(){}
		virtual void Update() {} //do not use if using a separate control on the layers for rendering purposes. 
		virtual void Render() {} //
		virtual void OnEvent(Events& event) {}

		//to be implemented later
		//virtual void EnableLayer();
		//virtual void DisableLayer(); 


		inline const std::string& GetName() const { return layer_name; } //debug for layer name - not for release type builds

	private:
		std::string layer_name; 

	};
}


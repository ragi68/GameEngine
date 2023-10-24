#pragma once
#include "Proto/EntryCore.h"
#include "LayerClass.h"

#include <vector>

namespace Proto{
	class PROTO_API Stackable
	{
	public:
		Stackable();
		~Stackable();

		void PushLayer(LayerClass* layer);
		void PopLayer(LayerClass* layer);
		void PushBelowLayers(LayerClass* layer);
		void PopBelowLayers(LayerClass* layer);

		std::vector<LayerClass*>::iterator begin() { return layer_stack.begin(); }
		std::vector<LayerClass*>::iterator end() { return layer_stack.end(); }

		private:
		std::vector<LayerClass*> layer_stack;
		int layerIndex = 0; //helps iterate over a vector without using too much memory
		//previous use of iterator created too many chances of memory leak compared to direct indexing. 

	};
}


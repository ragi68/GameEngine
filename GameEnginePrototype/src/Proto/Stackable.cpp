#include "PrecompiledHeaders.h"
#include "Stackable.h"

namespace Proto {
	Stackable::Stackable() {

	}

	Stackable::~Stackable() {
		for (LayerClass* layer : layer_stack) {
			delete layer;
		} 

		 
	}

	void Stackable::PushLayer(LayerClass* layer) { //insert a layerclass obejct into the vector object at position iterator, which is just the top
		layer_stack.emplace(layer_stack.begin() + layerIndex, layer);
		layerIndex++; //inserts layer into stack and then makes sure the layer is now on the nex.t 
	}

	void Stackable::PushBelowLayers(LayerClass* layers) {
		layer_stack.emplace_back(layers); //puts layer at the bottom of the stack
	}

	void Stackable::PopLayer(LayerClass* layer) {
		auto i = std::find(layer_stack.begin(), layer_stack.end(), layer); //finds the location of the said layer in between the end and beginning
		if (i != layer_stack.end()) {
			layer_stack.erase(i);
			layerIndex--;
		}
	}

	void Stackable::PopBelowLayers(LayerClass* layers) { //makes sure that all below layers are at the bottom of the stack and then pop then those are done
		auto i = std::find(layer_stack.begin(), layer_stack.end(), layers);
		if (i != layer_stack.end()) {
			layer_stack.erase(i);
		}
	}
}
 //iterators are simply pointers that iterate through each memeory adress in the Vector object. Plus 1 each time means you move one more into the stack and into the next element. 
//above line done thru integer indexing 
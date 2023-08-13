#include "ProtoHeader.h"


class FirstLayer : public Proto::LayerClass {
public:
	FirstLayer(): LayerClass("layer 1"){}
	void Update() override {

	}

	void OnEvent(Proto::Events& e) override{

	}


};


class ProtoType : public Proto::Application {
public:
	ProtoType() {
		PushLayer(new FirstLayer()); 
		PushBelowLayer(new Proto::IMGUI_Layer());

	}

	~ProtoType() {

	}
};


Proto::Application* Proto::StartUp() {
	return new ProtoType();
}
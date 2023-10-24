#include "ProtoHeader.h"


class FirstLayer : public Proto::LayerClass {
public:
	FirstLayer(): LayerClass("layer 1"){}
	void Update() override {

	}

	void OnEvent(Proto::Events& e) override{
		if (e.GetEvent() == Proto::EventTypes::KeyPressed) {
			Proto::KeyPressed& e2 = (Proto::KeyPressed&)e;
			PROTO_INFO_MODULE((char)e2.GetKeyCode()); 
		}
	}


};


class ProtoType : public Proto::Application {
public:
	ProtoType() {
		PushLayer(new FirstLayer()); 

	}

	~ProtoType() {

	}
};


Proto::Application* Proto::StartUp() {
	return new ProtoType();
}
#include "ProtoHeader.h"


class FirstLayer : public Proto::LayerClass {
public:
	FirstLayer(): LayerClass("layer 1"){}
	void Update() override {
		PROTO_INFO_MODULE("Updated First Layer ever!");

	}

	void OnEvent(Proto::Events& e) override{
		PROTO_TRACE_MODULE("{0}", e);

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
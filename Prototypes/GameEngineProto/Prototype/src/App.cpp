#include "ProtoHeader.h"

class ProtoType : public Proto::Application {
public:
	ProtoType() {

	}

	~ProtoType() {

	}
};


Proto::Application* Proto::StartUp() {
	return new ProtoType();
}
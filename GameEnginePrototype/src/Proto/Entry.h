#pragma once

#ifdef PROTO_PLATFORM_WINDOWS

extern Proto::Application* Proto::StartUp();

int main(int argc, char** argv) {

	Proto::logging::Init();
	PROTO_WARNING_MODULE("Hello from Logger.");

	CLIENT_INFO_MODULE("Hello from Logger. Var={0}");


	auto prototype = Proto::StartUp();
	prototype->RunApp();
	delete prototype;

}

#endif
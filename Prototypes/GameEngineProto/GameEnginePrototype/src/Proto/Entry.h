#pragma once

#ifdef PROTO_PLATFORM_WINDOWS

extern Proto::Application* Proto::StartUp();

int main(int argc, char** argv) {
	auto prototype = Proto::StartUp();
	prototype->RunApp();
	delete prototype;

}

#endif
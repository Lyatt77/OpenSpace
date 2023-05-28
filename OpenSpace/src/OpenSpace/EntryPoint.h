#pragma once

#ifdef OP_PLATFORM_WINDOWS

extern OpenSpace::Application* OpenSpace::CreateApplication();

int main(int argc, char** argv)
{ 
	OpenSpace::Log::Init();
	OP_CORE_WARN("Initialised Log!");
	int a = 5;
	OP_INFO("Hello! Var={0}", a);

	auto app = OpenSpace::CreateApplication();
	app->Run();
	delete app;

}

#endif
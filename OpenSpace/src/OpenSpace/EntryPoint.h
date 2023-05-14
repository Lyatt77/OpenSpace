#pragma once

#ifdef OP_PLATFORM_WINDOWS

extern OpenSpace::Application* OpenSpace::CreateApplication();

int main(int argc, char** argv)
{
	auto app = OpenSpace::CreateApplication();
	app->Run();
	delete app;

}

#endif
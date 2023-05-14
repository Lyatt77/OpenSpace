#include <OpenSpace.h>

class Sandbox : public OpenSpace::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

OpenSpace::Application* OpenSpace::CreateApplication()
{
	return new Sandbox();
}
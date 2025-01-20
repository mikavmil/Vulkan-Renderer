#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <functional>

class Renderer {
public:
	void run() {
		initVulkan();
		mainLoop();
		cleanup();
	}
private:
	void initVulkan() {
	}

	void mainLoop() {

	}

	void cleanup() {

	}
};

int main() {
	Renderer app;

	try
	{
		app.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
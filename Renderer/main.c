#include <stdio.h>
#include <stdlib.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

const uint32_t WIN_WIDTH = 800;
const uint32_t WIN_HEIGHT = 600;
const char* WIN_TITLE = "Vulkan Renderer";

typedef struct App{
	GLFWwindow* window;
	VkInstance instance;
} App;

void initWindow(App* pApp);
void initVulkan(App* pApp);
void mainLoop(App* pApp);
void cleanup(App* pApp);
void createInstance(App* pApp);

int main() {
	App app = {0};


	initWindow(&app);
	initVulkan(&app);
	mainLoop(&app);
	cleanup(&app);

	return 0;
}

void initWindow(App *pApp) {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	pApp->window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, NULL, NULL);
}

void initVulkan(App* pApp) {
	createInstance(pApp);

}

void mainLoop(App *pApp) {
	while (!glfwWindowShouldClose(pApp->window)) {
		glfwPollEvents();
	}
}

void cleanup(App* pApp) {
	glfwDestroyWindow(pApp->window);
	glfwTerminate();
}

void createInstance(App* pApp) {
	VkApplicationInfo appInfo = { 
		.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
		.pApplicationName = WIN_TITLE,
		.applicationVersion = VK_MAKE_VERSION(1, 0, 0),
		.pEngineName = "No Engine",
		.engineVersion = VK_MAKE_VERSION(1, 0, 0),
		.apiVersion = VK_API_VERSION_1_0
	};
}

VkInstanceCreateInfo createInfo = {
	.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
	.pApplicationInfo = &appInfo
};
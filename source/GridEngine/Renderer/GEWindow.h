//
// Created by mendel on 10/14/24.
//

#ifndef GEWINDOW_H
#define GEWINDOW_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace GE {

class GEWindow {
public:
	GEWindow(int w, int h, const std::string& name);
	~GEWindow();

	GEWindow(const GEWindow&) = delete;
	GEWindow& operator=(const GEWindow&) = delete;
	GEWindow(GEWindow&&) = delete;
	GEWindow& operator=(GEWindow&&) = delete;


	inline bool shouldClose() {return glfwWindowShouldClose(window);}
	VkExtent2D getExtent() const {return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};}
	inline bool wasWindowResized() const { return framebufferResized; }
	void resetWindowResizedFlag() { framebufferResized = false; }

	void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

private:
	static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    void initWindow();

    int width;
    int height;
	bool framebufferResized = false;

    std::string windowName;
    GLFWwindow* window;

};

} // GE

#endif //GEWINDOW_H

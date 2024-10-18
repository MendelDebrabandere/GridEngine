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

	void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

    private:
      void initWindow();

      const int width;
      const int height;

      std::string windowName;
      GLFWwindow* window;

};

} // GE

#endif //GEWINDOW_H

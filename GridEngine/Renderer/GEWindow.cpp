//
// Created by mendel on 10/14/24.
//

#include "GEWindow.h"

#include <stdexcept>

namespace GE {

GEWindow::GEWindow(int w, int h, const std::string& name)
    : width{w},
      height{h},
      windowName{name}
{
    initWindow();
}

GEWindow::~GEWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void GEWindow::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
}

void GEWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create window surface!");
    }

}

} // GE

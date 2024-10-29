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

void GEWindow::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    auto geWindow = reinterpret_cast<GEWindow*>(glfwGetWindowUserPointer(window));
    geWindow->framebufferResized = true;
    geWindow->width = width;
    geWindow->height = height;
}

void GEWindow::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

void GEWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create window surface!");
    }

}

} // GE

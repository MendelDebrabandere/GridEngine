//
// Created by mendel on 10/14/24.
//

#ifndef FIRSTAPP_H
#define FIRSTAPP_H

#include "Renderer/GEWindow.h"
#include "Renderer/GEPipeline.h"
#include "Renderer/GEDevice.h"
#include "Renderer/GESwapChain.h"

#include <memory>
#include <vector>

namespace GE {

class FirstApp {

public:

    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    FirstApp();
    ~FirstApp();

    FirstApp(const FirstApp&) = delete;
    FirstApp& operator=(const FirstApp&) = delete;
    FirstApp(FirstApp&&) = delete;
    FirstApp& operator=(FirstApp&&) = delete;

    void run();

private:
    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void drawFrame();

    GEWindow geWindow{WIDTH, HEIGHT, "GridEngine"};
    GEDevice geDevice{geWindow};
    GESwapChain geSwapChain{geDevice, geWindow.getExtent()};
    std::unique_ptr<GEPipeline> gePipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;
};

} // GE

#endif //FIRSTAPP_H

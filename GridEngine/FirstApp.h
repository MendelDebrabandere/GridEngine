//
// Created by mendel on 10/14/24.
//

#ifndef FIRSTAPP_H
#define FIRSTAPP_H

#include "Renderer/GEWindow.h"
#include "Renderer/GEPipeline.h"
#include "Renderer/GEDevice.h"
#include "Renderer/GESwapChain.h"
#include "Renderer/GEModel.h"

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
    void createSerpinskiTriangle(std::vector<GEModel::Vertex> &vertices, int depth, glm::vec2 left, glm::vec2 right, glm::vec2 top);

    void loadModels();
    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void freeCommandBuffers();
    void drawFrame();
    void recreateSwapChain();
    void recordCommandBuffer(int imageIndex);

    GEWindow geWindow{WIDTH, HEIGHT, "GridEngine"};
    GEDevice geDevice{geWindow};
    std::unique_ptr<GESwapChain> geSwapChain;
    std::unique_ptr<GEPipeline> gePipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;
    std::unique_ptr<GEModel> geModel;
};

} // GE

#endif //FIRSTAPP_H

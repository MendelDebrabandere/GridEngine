//
// Created by mendel on 10/14/24.
//

#ifndef FIRSTAPP_H
#define FIRSTAPP_H

#include "Renderer/GEWindow.h"
#include "Renderer/GEPipeline.h"
#include "Renderer/GEDevice.h"

namespace GE {

class FirstApp {

public:

    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    void run();

private:

    GEWindow ge_window{WIDTH, HEIGHT, "Hello Vulkan!"};
    GEDevice ge_device{ge_window};
    GEPipeline ge_pipeline{ge_device, "/GridEngine/Shaders/simple_shader.vert.spv", "/GridEngine/Shaders/simple_shader.frag.spv", GEPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};

};

} // GE

#endif //FIRSTAPP_H

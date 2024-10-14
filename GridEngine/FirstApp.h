//
// Created by mendel on 10/14/24.
//

#ifndef FIRSTAPP_H
#define FIRSTAPP_H

#include "Renderer/GEWindow.h"

namespace GE {

class FirstApp {

public:

    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    void run();

private:

    GEWindow ge_window{WIDTH, HEIGHT, "Hello Vulkan!"};

};

} // GE

#endif //FIRSTAPP_H

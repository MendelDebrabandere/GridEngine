#include <exception>

#include "FirstApp.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>


int main() {
    GE::FirstApp app{};

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
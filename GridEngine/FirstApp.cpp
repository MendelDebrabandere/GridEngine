//
// Created by mendel on 10/14/24.
//

#include "FirstApp.h"

namespace GE {

void FirstApp::run() {
	while (!ge_window.shouldClose()) {
		glfwPollEvents();
	}
}


} // GE
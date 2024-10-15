//
// Created by mendel on 10/14/24.
//

#include "GEPipeline.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace GE {

	GEPipeline::GEPipeline(const std::string& vertFilepath, const std::string& fragFilepath) {
		createGraphicsPipeline(vertFilepath, fragFilepath);
	}

	std::vector<char> GEPipeline::readFile(const std::string& filepath) {

		std::ifstream file(std::string(PROJECT_ROOT) + filepath, std::ios::ate | std::ios::binary);

		if (!file.is_open()) {
			throw std::runtime_error("Failed to open file: " + filepath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);
		file.close();
		return buffer;
	}

	void GEPipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath) {

		auto vertCode = readFile(vertFilepath);
		auto fragCode = readFile(fragFilepath);

		std::cout << "Vertex Shader Code Size: " << vertCode.size() << std::endl;
		std::cout << "Fragment Shader Code Size: " << fragCode.size() << std::endl;
	}

} // GE
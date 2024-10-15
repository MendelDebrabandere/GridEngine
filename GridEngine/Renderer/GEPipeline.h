//
// Created by mendel on 10/14/24.
//

#ifndef GEPIPELINE_H
#define GEPIPELINE_H
#include "GEDevice.h"

#include <string>
#include <vector>

namespace GE {

struct PipelineConfigInfo {

};

class GEPipeline {
public:
	GEPipeline(GEDevice &device, const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);
	~GEPipeline(){};

	GEPipeline(const GEPipeline&) = delete;
	GEPipeline& operator=(const GEPipeline&) = delete;
	GEPipeline(GEPipeline&&) = delete;
	GEPipeline& operator=(GEPipeline&&) = delete;

	static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

private:
	static std::vector<char> readFile(const std::string& filepath);

	void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);

	void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

	GEDevice& geDevice;
	VkPipeline graphicsPipeline;
	VkShaderModule vertShaderModule;
	VkShaderModule fragShaderModule;

};

} // GE

#endif //GEPIPELINE_H

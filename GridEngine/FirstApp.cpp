//
// Created by mendel on 10/14/24.
//

#include "FirstApp.h"

#include <stdexcept>
#include <array>

namespace GE {

FirstApp::FirstApp()
{
	loadModels();
	createPipelineLayout();
	createPipeline();
	createCommandBuffers();
}

FirstApp::~FirstApp()
{
	vkDestroyPipelineLayout(geDevice.device(), pipelineLayout, nullptr);
}

void FirstApp::run()
{
	while (!geWindow.shouldClose())
	{
		glfwPollEvents();
		drawFrame();
	}

	vkDeviceWaitIdle(geDevice.device());
}

void FirstApp::createSerpiskiTriangle(std::vector<GEModel::Vertex> &vertices, int depth, glm::vec2 left, glm::vec2 right, glm::vec2 top)
{
	if (depth <= 0)
	{
		vertices.push_back({top});
		vertices.push_back({right});
		vertices.push_back({left});
	}
	else
	{
		auto leftTop = 0.5f * (left + top);
		auto rightTop = 0.5f * (right + top);
		auto leftRight = 0.5f * (left + right);
		createSerpiskiTriangle(vertices, depth - 1, left, leftRight, leftTop);
		createSerpiskiTriangle(vertices, depth - 1, leftRight, right, rightTop);
		createSerpiskiTriangle(vertices, depth - 1, leftTop, rightTop, top);
	}
}

void FirstApp::loadModels()
{
	std::vector<GEModel::Vertex> vertices = {
		{{0.0f,-0.5f}, {1.0f, 0.0f, 0.0f}},
		{{0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}},
		{{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}}
	};
	//std::vector<GEModel::Vertex> vertices{};
	//createSerpiskiTriangle(vertices, 5, {-0.8f, 0.8f}, {0.8f, 0.8f}, {0.0f,-0.8f} );

	geModel = std::make_unique<GEModel>(geDevice, vertices);
}

void FirstApp::createPipelineLayout()
{
	VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo{};
	pipelineLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	pipelineLayoutCreateInfo.setLayoutCount = 0;
	pipelineLayoutCreateInfo.pSetLayouts = nullptr;
	pipelineLayoutCreateInfo.pushConstantRangeCount = 0;
	pipelineLayoutCreateInfo.pPushConstantRanges = nullptr;
	if (vkCreatePipelineLayout(geDevice.device(), &pipelineLayoutCreateInfo, nullptr, &pipelineLayout) != VK_SUCCESS)
	{
		throw std::runtime_error("failed to create pipeline layout");
	}
}

void FirstApp::createPipeline()
{
	auto pipelineConfig = GEPipeline::defaultPipelineConfigInfo(geSwapChain.width(), geSwapChain.height());
	pipelineConfig.renderPass = geSwapChain.getRenderPass();
	pipelineConfig.pipelineLayout = pipelineLayout;
	gePipeline = std::make_unique<GEPipeline>(\
		geDevice,
		"/GridEngine/Shaders/simple_shader.vert.spv",
		"/GridEngine/Shaders/simple_shader.frag.spv",
		pipelineConfig);
}

void FirstApp::createCommandBuffers()
{
	commandBuffers.resize(geSwapChain.imageCount());

	VkCommandBufferAllocateInfo allocInfo{};
	allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	allocInfo.commandPool = geDevice.getCommandPool();
	allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());

	if (vkAllocateCommandBuffers(geDevice.device(), &allocInfo, commandBuffers.data()) != VK_SUCCESS)
	{
		throw std::runtime_error("failed to allocate command buffers");
	}


	for (int i{} ; i < commandBuffers.size() ; ++i)
	{
		VkCommandBufferBeginInfo beginInfo{};
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

		if (vkBeginCommandBuffer(commandBuffers[i], &beginInfo) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to begin recording command buffer!");
		}

		VkRenderPassBeginInfo renderPassInfo{};
		renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		renderPassInfo.renderPass = geSwapChain.getRenderPass();
		renderPassInfo.framebuffer = geSwapChain.getFrameBuffer(i);

		renderPassInfo.renderArea.offset = {0, 0};
		renderPassInfo.renderArea.extent = geSwapChain.getSwapChainExtent();

		std::array<VkClearValue, 2> clearValues{};
		clearValues[0].color = {0.1f, 0.1f, 0.1f, 1.0f};
		clearValues[1].depthStencil = {1.0f, 0};
		renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
		renderPassInfo.pClearValues = clearValues.data();

		vkCmdBeginRenderPass(commandBuffers[i], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

		gePipeline->bind(commandBuffers[i]);
		geModel->bind(commandBuffers[i]);
		geModel->draw(commandBuffers[i]);

		vkCmdEndRenderPass(commandBuffers[i]);
		if (vkEndCommandBuffer(commandBuffers[i]) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to record command buffer!");
		}
	}
}

void FirstApp::drawFrame()
{
	uint32_t imageIndex = 0;
	auto result =geSwapChain.acquireNextImage(&imageIndex);
	if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
	{
		throw std::runtime_error("failed to acquire swap chain image!");
	}

	result = geSwapChain.submitCommandBuffers(&commandBuffers[imageIndex], &imageIndex);
	if (result != VK_SUCCESS)
	{
		throw std::runtime_error("failed to submit swap chain command buffer!");
	}
}

} // GE
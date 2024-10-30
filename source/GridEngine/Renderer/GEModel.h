//
// Created by mendel on 10/18/24.
//

#ifndef GEMODEL_H
#define GEMODEL_H

#include "GEDevice.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

#include <vector>



namespace GE {

class GEModel {

public:

    struct Vertex
    {
        glm::vec2 position;
        glm::vec3 color;

        static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
        static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
    };


    GEModel(GEDevice& device, const std::vector<Vertex>& vertices);
    ~GEModel();

    GEModel(const GEModel&) = delete;
    GEModel& operator=(const GEModel&) = delete;
    GEModel(GEModel&&) = delete;
    GEModel& operator=(GEModel&&) = delete;

    void bind(VkCommandBuffer commandBuffer);
    void draw(VkCommandBuffer commandBuffer);

private :

    void createVertexBuffers(const std::vector<Vertex>& vertices);

    GEDevice& geDevice;
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    uint32_t vertexCount;


};

} // GE

#endif //GEMODEL_H

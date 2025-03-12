#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include <QVulkanWindow>
#include <vector>
#include <string>
#include "vertex.h"

class VisualObject
{
public:
    VisualObject();  // Constructor

    // Getter and setter for object name
    void setName(std::string name);
    std::string getName() const;

    // Getter for vertices
    std::vector<Vertex> getVertices();

    QMatrix4x4 mMatrix;
    void move(float x, float y, float z) {
        mMatrix.translate(x, y, z);
    }
    void scale(float s) {
        mMatrix.scale(s);
    }
    void rotate(float t, float x, float y, float z) {
        mMatrix.rotate(t, x, y, z);
    }

    // Virtual update function (for dynamic objects)
    virtual void update() {}

    // Vulkan-related members (exposed for renderer to use)
    std::vector<Vertex> mVertices;  // Vertices for the visual object
    VkDeviceMemory mBufferMemory{ VK_NULL_HANDLE };  // Memory buffer for vertex data
    VkBuffer mBuffer{ VK_NULL_HANDLE };  // Vulkan buffer handle for vertices
    VkPrimitiveTopology mTopology{ VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST };  // Default to triangles

    // Transformation matrix


protected:
    std::string mName;  // Object's name

};

#endif // VISUALOBJECT_H

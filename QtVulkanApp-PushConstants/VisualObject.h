#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H


#include <QVulkanWindow>
#include <vector>
#include "vertex.h"


class VisualObject
{
public:
    std::vector<Vertex> mVertices;
    std::vector<Vertex> getVertices() { return mVertices; }
    VisualObject();
    //
    VkDeviceMemory mBufferMemory{ VK_NULL_HANDLE };
    VkBuffer mBuffer{ VK_NULL_HANDLE };
    VkPrimitiveTopology mTopology { VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST };
    //
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

};


#endif // VISUALOBJECT_H

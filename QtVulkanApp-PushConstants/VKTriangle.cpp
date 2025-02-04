#include <vector>
#include "Vertex.h"
#include "VisualObject.h"

class VkTriangle : public VisualObject {
public:
    //std::vector<Vertex> mVertices;
    VkTriangle();
    //std::vector<Vertex> getVertices() { return mVertices; }
};


VkTriangle::VkTriangle() : VisualObject()
{
    Vertex v1{-1.0f,   0.0f,  0.0f,   1.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    Vertex v2{1.0f,   0.0f,  0.0f,   0.0f, 1.0f, 0.0f, 0.0f, 0.0f};
    Vertex v3{0.0f,   1.0f,  0.0f,   0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v3);
}

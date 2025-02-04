#include "VKTriangle.h"
#include <vector>
#include "Vertex.h"
#include "VisualObject.h"

class VKTriangle : public VisualObject {
public:
    //std::vector<Vertex> mVertices;
    VKTriangle();
    //std::vector<Vertex> getVertices() { return mVertices; }
};


VkTriangle::VkTriangle() : VisualObject()
{
    mVertices.push_back(Vertex{-0.5f,   0.0f,  0.0f,   1.0f, 0.0f, 0.0f, 0.0f, 0.0f});
    mVertices.push_back(Vertex{-0.5f,   -0.5f,  0.0f,   0.0f, 1.0f, 0.0f, 0.0f, 0.0f});
    mVertices.push_back(Vertex{0.0f,   0.0f,  0.0f,   0.0f, 0.0f, 1.0f, 0.0f, 0.0f});


    // Flytter trekanten litt til venstre og lagrer translasjonen i en 4x4 matrise
    mMatrix.translate(-100.f, 0, 0);
}


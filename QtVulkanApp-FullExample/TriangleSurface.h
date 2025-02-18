#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H
#include <string>
#include "visualobject.h"

class VkTriangleSurface : public VisualObject
{
public:
    //std::vector<Vertex> mVertices;
    //std::vector<Vertex> getVertices() { return mVertices; }
    VkTriangleSurface();
    VkTriangleSurface(const std::string& filename);
};

#endif // TRIANGLESURFACE_H

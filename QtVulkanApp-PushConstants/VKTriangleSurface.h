#ifndef VKTRIANGLESURFACE_H
#define VKTRIANGLESURFACE_H
#include <vector>
#include <string>
#include "vertex.h"
#include "visualobject.h"


class VKTriangleSurface : public VisualObject
{
public:
    //std::vector<Vertex> mVertices;
    //std::vector<Vertex> getVertices() { return mVertices; }
    VKTriangleSurface();
    VKTriangleSurface(const std::string& filename);
};


#endif // VKTRIANGLESURFACE_H

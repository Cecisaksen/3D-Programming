#ifndef VKTRIANGLESURFACE_H
#define VKTRIANGLESURFACE_H
#include <string>
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

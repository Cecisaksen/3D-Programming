#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H
#include <string>
#include "visualobject.h"

class TriangleSurface : public VisualObject
{
public:
    //std::vector<Vertex> mVertices;
    //std::vector<Vertex> getVertices() { return mVertices; }
    TriangleSurface();
    TriangleSurface(const std::string& filename);
};

#endif // TRIANGLESURFACE_H

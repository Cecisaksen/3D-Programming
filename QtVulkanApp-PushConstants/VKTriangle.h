#ifndef VKTRIANGLE_H
#define VKTRIANGLE_H

#include <vector>
#include "vertex.h"


class VKTriangle {
public:
    std::vector<Vertex> mVertices;
    VKTriangle();
    std::vector<Vertex> getVertices() { return mVertices; }
};


#endif // VKTRIANGLE_H



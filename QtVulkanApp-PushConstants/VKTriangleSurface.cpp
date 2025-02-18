#include "VKTriangleSurface.h"
#include "vertex.h"
#include "visualobject.h"
#include <fstream>

VKTriangleSurface::VKTriangleSurface() : VisualObject()
{
    Vertex v1{0.0f,   0.0f,  0.0f,   1.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    Vertex v2{1.0f,   0.0f,  0.0f,   0.0f, 1.0f, 0.0f, 0.0f, 0.0f};
    Vertex v3{0.0f,   1.0f,  0.0f,   0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    Vertex v4{1.0f,   1.0f,  0.0f,   1.0f, 1.0f, 0.0f, 0.0f, 0.0f};
    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v3);
    mVertices.push_back(v3);
    mVertices.push_back(v2);
    mVertices.push_back(v4);


    //  Skalerer ned kvadratet i eget koordinatsystem/frame
    mMatrix.scale(0.25f);
    mMatrix.translate(-30.f, 0, 0);
}


VKTriangleSurface::VKTriangleSurface(const std::string &filename)
{
    std::ifstream inn(filename);
    if (!inn.is_open())
        return;

}

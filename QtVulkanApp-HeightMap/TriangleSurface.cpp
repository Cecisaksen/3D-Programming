#include "TriangleSurface.h"
#include <fstream>
#include <QDebug>
TriangleSurface::TriangleSurface() : VisualObject()
{
    // Define vertices for a 1x1 square in the XZ-plane (Square, not rectangle)
    Vertex v1{0.0f, 0.0f,  0.0f,  0.5f, 0.5f, 0.5f, 0.0f, 0.0f}; // Bottom-left
    Vertex v2{1.0f, 0.0f,  0.0f,  0.5f, 0.5f, 0.5f, 0.0f, 0.0f}; // Bottom-right
    Vertex v3{0.0f, 0.0f,  1.0f,  0.5f, 0.5f, 0.5f, 0.0f, 0.0f}; // Top-left
    Vertex v4{1.0f, 0.0f,  1.0f,  0.5f, 0.5f, 0.5f, 0.0f, 0.0f}; // Top-right

    // First triangle (bottom-left, bottom-right, top-left)
    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v3);

    // Second triangle (top-left, bottom-right, top-right)
    mVertices.push_back(v3);
    mVertices.push_back(v2);
    mVertices.push_back(v4);

    mMatrix.scale(10.0f);

    mMatrix.translate(0.0f, 0.0f, 0.0f);
}


TriangleSurface::TriangleSurface(const std::string &filename)
{
    std::ifstream inn(filename);
    if (!inn.is_open())
        return;

    int n;
    Vertex v;
    inn >> n;
    for (auto i=0; i<n; i++)
    {
        inn >> v;
        mVertices.push_back(v);
        //qDebug() << v.x << v.y << v.z;
    }
    inn.close();
}

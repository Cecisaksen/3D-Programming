#ifndef SPIRAL_H
#define SPIRAL_H

#include "VisualObject.h"
#include <vector>

class Spiral : public VisualObject
{
public:
    Spiral(float numLoops = 5.0f, float numPoints = 100.0f, float scale = 1.0f);

    // Function to get the vertices of the spiral
    std::vector<Vertex>& getVertices() { return mVertices; }

private:
    void generateSpiral(float numLoops, float numPoints, float scale);
};

#endif // SPIRAL_H

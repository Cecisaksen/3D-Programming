#ifndef FUNCTIONGRAPH_H
#define FUNCTIONGRAPH_H

#include "VisualObject.h"
#include "Vertex.h"
#include <vector>

class FunctionGraph : public VisualObject {
public:

    FunctionGraph();

    float derivative(float x, float y, float h);

private:

    void generateGraphVertices(float lowerX, float upperX, float lowerY, float upperY);
};

#endif  // FUNCTIONGRAPH_H

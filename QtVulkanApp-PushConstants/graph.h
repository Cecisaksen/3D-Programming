#ifndef GRAPH_H
#define GRAPH_H

#include "VisualObject.h"
#include "Vertex.h"
#include <vector>

class graph : public VisualObject {
public:
    graph();  // Constructor

    // Function to calculate the derivative of f(x)
    float derivative(float x, float h);

private:
    // Function to generate graph vertices dynamically
    void generateGraphVertices(float lower, float upper);
};

#endif  // GRAPH_H

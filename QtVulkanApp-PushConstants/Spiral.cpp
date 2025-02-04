#include "Spiral.h"
#include <cmath>
#include <iostream>

// Constructor for the Spiral class
Spiral::Spiral(float numLoops, float numPoints, float scale) : VisualObject()
{
    generateSpiral(numLoops, numPoints, scale);

    // Optionally translate the spiral to a different position
    mMatrix.translate(-0.25f, 0, 0);  // This is just an example of translation, feel free to adjust
}

// Function to generate the vertices of the spiral
void Spiral::generateSpiral(float numLoops, float numPoints, float scale)
{
    mVertices.clear();  // Clear any existing vertices

    float t_step = 1.0f / numPoints;  // Step for parameter t
    int count = 0;  // For debugging or any use case

    // Generate 3D spiral points: x = r*cos(t), y = r*sin(t), z = t
    for (int i = 0; i < numPoints; ++i) {
        float t = i * t_step;
        float angle = 2 * M_PI * numLoops * t;
        float x = scale * t * cos(angle);
        float y = scale * t * sin(angle);
        float z = scale * t;  // Z increases linearly with t to create the spiral

        // Color vertices with alternating colors for visibility
        float r = (i % 2 == 0) ? 1.0f : 0.5f;
        float g = 0.0f;
        float b = (i % 2 == 0) ? 0.0f : 1.0f;

        // Add the vertex to the mVertices array
        mVertices.push_back(Vertex{x, y, z, r, g, b, 0.0f, 0.0f});

        count++;
    }
}

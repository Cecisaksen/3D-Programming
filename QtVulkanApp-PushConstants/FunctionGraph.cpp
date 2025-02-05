#include "FunctionGraph.h"
#include "Vertex.h"
#include <cmath>
#include <fstream>
#include <iostream>

FunctionGraph::FunctionGraph() : VisualObject()
{
    // Define the range and resolution for x and y
    float xLower = 5.0f;
    float xUpper = -5.0f;
    float yLower = 5.0f;
    float yUpper = -5.0f;
    int xIntervals = 10;  // Number of intervals for x
    int yIntervals = 10;  // Number of intervals for y

    float xStep = (xUpper - xLower) / (xIntervals);
    float yStep = (yUpper - yLower) / (yIntervals);

    // Create a file to save the vertex data
    std::ofstream file("vertexData.txt");

    // Compute total number of lines and write that as the first line
    int totalVertices = (xIntervals + 1) * (yIntervals + 1);
    file << totalVertices << std::endl;

    // Iterate over the x and y ranges
    for (int i = 0; i <= xIntervals; ++i)
    {
        for (int j = 0; j <= yIntervals; ++j)
        {
            // Compute x and y based on the current indices
            float x = xLower + i * xStep;
            float y = yLower + j * yStep;

            // Calculate the function value f(x, y) = x^2 * y^2
            float z = (x * x) * (y * y);  // f(x, y) = x^2 * y^2

            // Color determination based on the z-value
            float r = (z > 0) ? 1.0f : 0.0f;  // Red for positive z
            float g = (z > 0) ? 0.0f : 1.0f;  // Green for negative z
            float b = 0.0f;  // Keep blue as 0 for now (for simplicity)

            // Add vertex data to the vertex list
            mVertices.push_back(Vertex{x, y, z, r, g, b, 0.0f, 0.0f});

            // Write the vertex data to the file in the format: x y z r g b
            file << x << " " << y << " " << z << " " << r << " " << g << " " << b << std::endl;
        }
    }

    file.close();
    mMatrix.translate(30.0f, 0, 0);
}

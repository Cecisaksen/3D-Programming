#include "graph.h"
#include "VisualObject.h"
#include <cmath>
#include <fstream>

// Constructor
graph::graph() : VisualObject()
{
    float lower = -5.0f;   // Start of the x-range (a)
    float upper = 5.0f;    // End of the x-range (b)
    int n = 1000;           // Number of intervals (n)
    float h = (upper - lower) / n;

    std::ofstream file("vertexData.txt");
    file << (n + 1) << std::endl;

    for (int i = 0; i <= n; ++i)
    {
        float x = lower + i * h;
        float y = sin(x);           // Function value: f(x) = sin(x)

        // Calculate the derivative of f(x)
        float slope = derivative(x, h);

        // Determine color
        float r = slope > 0 ? 0.0f : 1.0f;  // Purple for decreasing slope
        float g = slope > 0 ? 1.0f : 0.0f;  // Green for increasing slope
        float b = slope > 0 ? 0.0f : 1.0f;  // Purple for decreasing slope

        // Add the vertex to the list with color based on slope
        mVertices.push_back(Vertex{x, y, 0.0f, r, g, b, 0.0f, 0.0f});

        // Write the vertex data to the file
        file << x << " " << y << " 0.0 " << r << " " << g << " " << b << std::endl;
    }

    file.close();

    mMatrix.translate(-0.25f, 0, 0);
}

float graph::derivative(float x, float h)
{
    return (sin(x + h) - sin(x - h)) / (2 * h);
}

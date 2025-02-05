#include "spiral.h"
#include "VisualObject.h"
#include "Vertex.h"
#include <cmath>
#include <fstream>
#include <vector>

Spiral::Spiral() : VisualObject()
{
    float t = 0.0f;           // Starting value of t
    float t_step = 0.01f;     // Step size for t (smaller value for smoother curve)
    float radius = 1.0f;      // Initial radius

    // Open the output file
    std::ofstream outfile("SpiralData.txt");

    // Check if file is opened correctly
    if (!outfile.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    int count = 0;

    // Generate the vertices for the spiral
    for (int i = 0; i < 1000; i++) {
        // Calculate angle, which increases with t
        float angle = 2 * M_PI * t;  // Full rotation every 2*pi

        // Calculate the x and y coordinates for the spiral's 2D circle
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        // Z-coordinate increases linearly with t for the upward movement of the spiral
        float z = t;  // This creates the height of the spiral

        // Write the vertex to the file
        outfile << x << " " << y << " " << z << std::endl;

        // Add the vertex to the list for later rendering
        mVertices.push_back(Vertex{x, y, z, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f}); // Using red color for simplicity

        // Increment t and the radius to make the spiral grow outward
        t += t_step;
        radius += 0.001f;  // Gradual increase of radius for a smooth curve
        count++;
    }

    // Optionally, write the count of data points at the beginning of the file
    outfile.seekp(0, std::ios::beg);  // Go back to the start of the file
    outfile << "Line count: " << count << std::endl;

    // Close the output file
    outfile.close();

    // Optionally, log a message about the file creation
    std::cout << "Spiral data written to SpiralData.txt" << std::endl;

    mMatrix.translate(20.0f, 0.0f, 1.0f);
}

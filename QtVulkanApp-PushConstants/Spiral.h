#ifndef SPIRAL_H
#define SPIRAL_H

#include "VisualObject.h"
#include <QMatrix4x4>

class Spiral : public VisualObject
{
public:
    Spiral();  // Constructor to initialize the spiral

    // New method to rotate the spiral in 3D space
    void rotate(float angleX, float angleY, float angleZ);

private:
         // Any other members needed for the spiral can go here
};

#endif // SPIRAL_H

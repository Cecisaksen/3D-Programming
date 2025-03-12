#ifndef HOUSE_H
#define HOUSE_H

#include "VisualObject.h"

class House : public VisualObject {
public:
    House();
    void createHouse();
    void update();

    // Set the position for the roof independently of the house
    void setRoofPosition(float x, float y, float z);

private:
    QVector3D mPosition;
    QVector3D mRoofPosition;  // Store roof position
    float mWidth;
    float mDepth;
};

#endif // HOUSE_H

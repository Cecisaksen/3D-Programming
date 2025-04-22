#ifndef HOUSE_H
#define HOUSE_H

#include "VisualObject.h"

class House : public VisualObject {
public:
    House();
    void createHouse();
    void update();

private:
    QVector3D mPosition;
    float mWidth;
    float mDepth;
};

#endif // HOUSE_H

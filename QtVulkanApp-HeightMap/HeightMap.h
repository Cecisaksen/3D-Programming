#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include "VisualObject.h"
#include <string>

class HeightMap : public VisualObject
{
public:
    HeightMap();
    float GetHeight(float x, float z);

    void makeTerrain(std::string heightMapImage);

private:

    QImage Image;
};

#endif // HEIGHTMAP_H

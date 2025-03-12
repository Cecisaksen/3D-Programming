#include "VisualObject.h"

VisualObject::VisualObject()
{
    mMatrix.setToIdentity();
}

std::vector<Vertex> VisualObject::getVertices() {
    return mVertices;
}

void VisualObject::setName(std::string name)
{
    mName = name;
}

std::string VisualObject::getName() const
{
    return mName;
}

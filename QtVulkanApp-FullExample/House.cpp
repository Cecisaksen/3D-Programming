// House.cpp
#include "House.h"

House::House() : VisualObject() {
    createHouse();
    mPosition = QVector3D(10.0f, 0.0f, 10.0f);  // Initial position of the house
    mMatrix.setToIdentity();
    mMatrix.scale(1.0f);
    mMatrix.translate(mPosition);  // Position the house
}

void House::createHouse() {
    float width = 6.0f;
    float depth = 6.0f;
    float yPosition = 0.1f;

    mVertices.push_back(Vertex{-width / 2, yPosition, -depth / 2, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f});  // Bottom-left
    mVertices.push_back(Vertex{ width / 2, yPosition, -depth / 2, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f});  // Bottom-right
    mVertices.push_back(Vertex{-width / 2, yPosition,  depth / 2, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f});  // Top-left

    mVertices.push_back(Vertex{ width / 2, yPosition, -depth / 2, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f});  // Bottom-right
    mVertices.push_back(Vertex{ width / 2, yPosition,  depth / 2, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f});  // Top-right
    mVertices.push_back(Vertex{-width / 2, yPosition,  depth / 2, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f});  // Top-left
}

void House::update() {
    mMatrix.setToIdentity();
    mMatrix.translate(mPosition);  // Position the house
    mMatrix.scale(1.0f);

    // Ensure the roof is also positioned correctly
    mMatrix.translate(mRoofPosition);
}

void House::setRoofPosition(float x, float y, float z) {
    mRoofPosition = QVector3D(x, y, z);
    mMatrix.setToIdentity();
    mMatrix.translate(mRoofPosition);  // Update the position of the roof
}

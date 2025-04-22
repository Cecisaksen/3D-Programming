#include "Door.h"
#include "Player.h"

Door::Door() : VisualObject() {

    mDoorWidth = 3.0f;  // Set door width
    mDoorHeight = 3.0f; // Set door height
    mIsOpen = false;    // Initially, the door is closed
    createDoor();       // Create the door's vertices


    mMatrix.setToIdentity();
    mPosition = QVector3D(10.0f, 0.0f, 11.5f);  //initial position
    mMatrix.scale(1.0f);      // Scaling
    mMatrix.translate(mPosition);  // Position the door at its current position
}

void Door::createDoor() {
    float yPosition = 0.1f;  // Ground level

    // Vertices for a simple rectangular door
    mVertices.push_back(Vertex{-mDoorWidth / 2, yPosition, -mDoorHeight / 2, 1.0f, 0.647f, 0.0f, 1.0f, 0.0f});  // Bottom-left
    mVertices.push_back(Vertex{ mDoorWidth / 2, yPosition, -mDoorHeight / 2, 1.0f, 0.647f, 0.0f, 1.0f, 0.0f});  // Bottom-right
    mVertices.push_back(Vertex{-mDoorWidth / 2, yPosition,  mDoorHeight / 2, 1.0f, 0.647f, 0.0f, 1.0f, 0.0f});  // Top-left

    mVertices.push_back(Vertex{ mDoorWidth / 2, yPosition, -mDoorHeight / 2, 1.0f, 0.647f, 0.0f, 1.0f, 0.0f});  // Bottom-right
    mVertices.push_back(Vertex{ mDoorWidth / 2, yPosition,  mDoorHeight / 2, 1.0f, 0.647f, 0.0f, 1.0f, 0.0f});  // Top-right
    mVertices.push_back(Vertex{-mDoorWidth / 2, yPosition,  mDoorHeight / 2, 1.0f, 0.647f, 0.0f, 1.0f, 0.0f});  // Top-left
}

void Door::DoorCollision(class Player* player)
{
    QVector3D playerPos = player->getPosition();
    QVector3D diff = playerPos - mPosition;
    diff.setY(0.1f);  // Ignore the Y difference
    float distance = diff.length();


    float collisionThreshold = 2.f;
    if (distance < collisionThreshold)
    {
        mIsOpen = true;
        qDebug() << "DOOR! ";
    }
}

void Door::update() {
    mMatrix.setToIdentity();
    mMatrix.translate(mPosition);
}

void Door::setPosition(float x, float y, float z) {
    mPosition = QVector3D(x, y, z);
    mMatrix.setToIdentity();
    mMatrix.translate(mPosition);
}

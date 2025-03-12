#ifndef DOOR_H
#define DOOR_H

#include "VisualObject.h"

class Door : public VisualObject {
public:
    Door();
    void createDoor();
    void update();
     void DoorCollision(class Player* player);
    // Method to set position internally, just like House
    void setPosition(float x, float y, float z);

     bool mIsOpen;
private:
    float mDoorWidth;
    float mDoorHeight;

    // Add mPosition as a member variable to store the door's position
    QVector3D mPosition;  // Position of the door
};

#endif // DOOR_H

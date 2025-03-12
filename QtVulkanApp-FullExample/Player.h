#ifndef PLAYER_H
#define PLAYER_H

#include "VisualObject.h"
#include <QMatrix4x4>
#include <QVector3D>

class Pickup;

class Player : public VisualObject {
public:
    QVector3D mPosition;  // Player's position in the scene (XZ plane)

    Player();  // Constructor


    QVector3D getPosition() const;              // Getter for player's position
    void setPosition(const QVector3D& newPosition);  // Setter for player's position

    // Move the player along the XZ plane
    void move(float dx, float dz);
    QMatrix4x4 getModelMatrix() const { return mMatrix; }

    std::vector<Pickup*> pickupArr;
    Pickup* inHousePickup;
    std::vector<class NPC*> NPCArr;
    class Door* doorCopy;

    // Update the transformation matrix (if needed)
    virtual void update();

    // Move player using WASD keys
    float moveSpeed = 0.5f;

};

#endif // PLAYER_H

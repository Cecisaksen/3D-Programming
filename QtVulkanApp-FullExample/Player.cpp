#include "Player.h"
#include "Door.h"
#include "NPC.h"
#include "Pickup.h"
#include <QDebug>

Player::Player() : VisualObject(){

    float yPosition = 0.1f;  // Y-coordinate remains constant, only need it slightly higher than the plane

    mVertices.push_back(Vertex{-0.5f, yPosition, -0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f});
    mVertices.push_back(Vertex{ 0.5f, yPosition, -0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f});
    mVertices.push_back(Vertex{-0.5f, yPosition,  0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f});

    mVertices.push_back(Vertex{-0.5f, yPosition,  0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f});
    mVertices.push_back(Vertex{ 0.5f, yPosition, -0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f});
    mVertices.push_back(Vertex{ 0.5f, yPosition,  0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f});



    setPosition(QVector3D(25.0f, 1.0f, 25.0f));

}

QVector3D Player::getPosition() const {
    return mPosition;
}

void Player::setPosition(const QVector3D& newPosition) {
    mPosition = newPosition;

}

void Player::move(float dx, float dz) {

    mPosition.setX(mPosition.x() + dx * moveSpeed);
    mPosition.setZ(mPosition.z() + dz * moveSpeed);

    // Log the position to check if it's being updated
   // qDebug() << "Player Position: " << mPosition;
}

void Player::update() {
    // Apply translation directly to the transformation matrix based on the current position
    mMatrix.setToIdentity();  // Optional: reset matrix, depends on your needs
    mMatrix.translate(mPosition);  // Apply translation based on mPosition

    for (Pickup* pickup : pickupArr)
    {
        pickup->CollectCollision(this);
        pickup->update();
    }

    for(NPC* npc : NPCArr)
    {
        npc->NPCCollision(this);
        npc->update();

        if(npc->getIsColliding() == true)
        {
            moveSpeed = 0;
        }
    }

    doorCopy->DoorCollision(this);

    if(inHousePickup != nullptr)
    {
        inHousePickup->CollectCollision(this);
        inHousePickup->update();
    }


}

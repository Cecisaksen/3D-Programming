#include "NPC.h"
#include "Player.h"
#include <QDebug>
#include "Renderer.h"
// Constructor: Initialize NPC with specific start and end positions
NPC::NPC(const QVector3D& start, const QVector3D& end) : VisualObject(),
    mStart(start),
    mEnd(end),
    mCurrent(mEnd),  // Set initial target to mEnd so the NPC starts moving toward it
    mPatrolSpeed(0.05f)
{
    mPosition = mStart;  // Set initial position

    // Create vertices for the NPC visual (simple square)
    float yPosition = mStart.y() + 0.1f; // Adjust visual height based on start position

    mVertices.push_back(Vertex{-0.5f, yPosition, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});
    mVertices.push_back(Vertex{ 0.5f, yPosition, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});
    mVertices.push_back(Vertex{-0.5f, yPosition,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});

    mVertices.push_back(Vertex{-0.5f, yPosition,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});
    mVertices.push_back(Vertex{ 0.5f, yPosition, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});
    mVertices.push_back(Vertex{ 0.5f, yPosition,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});

    // Initialize the transform: scale then translate to the starting position
    mMatrix.scale(1.5f);
    mMatrix.translate(mPosition);
}

void NPC::NPCCollision(Player* player)
{

    QVector3D playerPos = player->getPosition();
    QVector3D diff = playerPos - mPosition;
    diff.setY(mStart.y() + 0.1f);  // Ignore the Y difference
    float distance = diff.length();

    // Set a collision threshold (adjust as needed)
    float collisionThreshold = 1.0f;
    if (distance < collisionThreshold)
    {
        isColliding = true;

        qDebug() << "YOU LOSE! ";
    } else {
        isColliding = false;
    }

}

// Update function: Moves the NPC between its patrol points
void NPC::update() {
    // Calculate direction towards current target (mCurrent)
    if(isColliding)
        return;

    if(doesExist == false)
        return;


    QVector3D direction = mCurrent - mPosition;
    float distance = direction.length();

    if (distance > mPatrolSpeed) {
        direction.normalize();
        mPosition += direction * mPatrolSpeed;
    } else {
        mPosition = mCurrent;
        // Switch patrol points
        if (mCurrent == mEnd)
            mCurrent = mStart;
        else
            mCurrent = mEnd;
    }

    // Update the transformation matrix with the new position
    mMatrix.setToIdentity();
    mMatrix.translate(mPosition);
}

// Getter for NPC's position
QVector3D NPC::getPosition() const {
    return mPosition;
}

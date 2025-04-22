#include "NPC.h"
#include "Player.h"
#include <QDebug>

NPC::NPC(const QVector3D& start, const QVector3D& end) : VisualObject(),
    mStart(start),
    mEnd(end),
    mCurrent(mEnd),
    mPatrolSpeed(0.05f)
{
    mPosition = mStart;  // Set initial position

    // Create vertices for the NPC
    float yPosition = mStart.y() + 0.1f;

    mVertices.push_back(Vertex{-0.5f, yPosition, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});
    mVertices.push_back(Vertex{ 0.5f, yPosition, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});
    mVertices.push_back(Vertex{-0.5f, yPosition,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});

    mVertices.push_back(Vertex{-0.5f, yPosition,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});
    mVertices.push_back(Vertex{ 0.5f, yPosition, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});
    mVertices.push_back(Vertex{ 0.5f, yPosition,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});

    mMatrix.scale(1.5f);
    mMatrix.translate(mPosition);
}

void NPC::NPCCollision(Player* player)
{

    QVector3D playerPos = player->getPosition();
    QVector3D diff = playerPos - mPosition;
    diff.setY(mStart.y() + 0.1f);
    float distance = diff.length();


    float collisionThreshold = 1.0f;
    if (distance < collisionThreshold)
    {
        isColliding = true;

        qDebug() << "YOU LOSE! ";
    } else {
        isColliding = false;
    }

}

void NPC::update() {

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

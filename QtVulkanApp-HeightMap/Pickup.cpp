#include "Pickup.h"
#include "Player.h"  // Needed for accessing Player::getPosition()
#include <QDebug>
#include <cstdlib>

int Pickup::sCollectedCount = 0;

Pickup::Pickup() : VisualObject(), mCollected(false)
{
    float randomX = static_cast<float>(rand() % 49);
    float randomZ = static_cast<float>(rand() % 49);
    float yPosition = 0.1f;
    mPosition = QVector3D(randomX, yPosition, randomZ);

    qDebug() << "Pickup position (after random):" << mPosition;

    Vertex v1{-0.5f, 0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};
    Vertex v2{ 0.5f, 0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};
    Vertex v3{-0.5f, 0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};
    Vertex v4{ 0.5f, 0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};

    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v3);
    mVertices.push_back(v3);
    mVertices.push_back(v2);
    mVertices.push_back(v4);

    mMatrix.scale(1.0f);
    mMatrix.translate(mPosition);

    qDebug() << "Pickup matrix after translation:" << mMatrix;
}

Pickup::Pickup(float x, float z) : VisualObject(), mCollected(false)
{
    float yPosition = 0.1f;
    mPosition = QVector3D(x, yPosition, z);

    Vertex v1{-0.5f, 0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};
    Vertex v2{ 0.5f, 0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};
    Vertex v3{-0.5f, 0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};
    Vertex v4{ 0.5f, 0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};

    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v3);
    mVertices.push_back(v3);
    mVertices.push_back(v2);
    mVertices.push_back(v4);

    mMatrix.scale(1.0f);
    mMatrix.translate(mPosition);
}

void Pickup::CollectCollision(Player* player)
{
    if (mCollected)
        return;

    QVector3D playerPos = player->getPosition();
    QVector3D diff = playerPos - mPosition;
    diff.setY(0);
    float distance = diff.length();


    float collisionThreshold = 1.0f;
    if (distance < collisionThreshold)
    {
        collect();
    }
}

void Pickup::collect()
{

    if (!mCollected) {
        mCollected = true;
        sCollectedCount++;
        qDebug() << "Player picked up" << sCollectedCount << "/7 pickups";
        if (sCollectedCount == 7) {
            qDebug() << "YOU WIN";
        }
    }
}

QVector3D Pickup::getPosition() const
{
    return mPosition;
}

void Pickup::setPosition(float x, float z)
{
    mPosition = QVector3D(x, 0.1f, z);
    mMatrix.setToIdentity();
    mMatrix.translate(mPosition);
}

bool Pickup::isCollected() const
{
    return mCollected;
}

void Pickup::reset()
{
    mCollected = false;
    mMatrix.setToIdentity();
    mMatrix.translate(mPosition);
}

void Pickup::update()
{
    if (mCollected)
    {
        mMatrix.setToIdentity();
        mMatrix.scale(0.0f);  // hiding the pickup by scaling it down
    }

}

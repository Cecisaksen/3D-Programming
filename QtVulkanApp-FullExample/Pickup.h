#ifndef PICKUP_H
#define PICKUP_H

#include "VisualObject.h"
#include <QVector3D>

// Forward declaration to avoid including Player.h here
class Player;

class Pickup : public VisualObject
{
public:
    Pickup();
    Pickup(float x, float z);

    // Called when a collision is detected
    void CollectCollision(Player* player);

    // Collect the pickup
    void collect();

    // Update pickup state if necessary (e.g., make it disappear)
    void update();

    QVector3D getPosition() const;
    void setPosition(float x, float z);

    bool isCollected() const;
    void reset();

    // Static counter to track the number of collected pickups
    static int sCollectedCount;

private:
    QVector3D mPosition;
    bool mCollected;
};

#endif // PICKUP_H

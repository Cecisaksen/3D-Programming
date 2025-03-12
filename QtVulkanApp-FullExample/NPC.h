#ifndef NPC_H
#define NPC_H

#include "VisualObject.h"
#include <QVector3D>
#include <string>

class NPC : public VisualObject {
public:
    // Constructor: Initialize NPC with a specific start and end position
    NPC(const QVector3D& start, const QVector3D& end);

    void NPCCollision(class Player* player);

    // Constructor: Load NPC's vertices from a file (if needed)
    NPC(const std::string &filename);

    // Update function to move the NPC between patrol points
    void update();

    // Getter for NPC's position
    QVector3D getPosition() const;

    bool getIsColliding(){return isColliding;}

    bool doesExist = true;

private:
    QVector3D mStart;    // Starting point of the patrol path
    QVector3D mEnd;      // Ending point of the patrol path
    QVector3D mCurrent;  // Current target patrol point (either mStart or mEnd)
    QVector3D mPosition; // Current position of the NPC
    float mPatrolSpeed;  // Speed of NPC movement between patrol points
    bool isColliding = false;
};

#endif // NPC_H

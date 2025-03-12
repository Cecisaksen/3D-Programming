#ifndef CAMERA_H
#define CAMERA_H

#include <QMatrix4x4>
#include <QVector3D>

class Camera {
private:
    QVector3D mEye;  // Camera position
    QVector3D mAt;   // The point the camera looks at (center of the plane)
    QVector3D mUp;   // The camera's "up" direction (along Z-axis)

    QMatrix4x4 mProjectionMatrix;  // Projection matrix
    QMatrix4x4 mViewMatrix;        // View matrix

public:
    Camera();
    ~Camera() {}

    void init();
    void perspective(int degrees, double aspect, double nearplane, double farplane);

    // Set the camera position to look down at the entire plane
    void setStaticPosition();

    void translate(float dx, float dy, float dz);
    void rotate(float angle, float x, float y, float z);

    QMatrix4x4 cMatrix();  // Returns the combined projection and view matrix

    // Optional getters for view/projection matrices if needed
    const QMatrix4x4& getViewMatrix() const { return mViewMatrix; }
};

#endif // CAMERA_H

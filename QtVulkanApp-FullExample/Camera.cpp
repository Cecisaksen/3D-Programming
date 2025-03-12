#include "Camera.h"

Camera::Camera() {
    // Initialize camera parameters and matrices
    mEye = QVector3D(50.0f, 150.0f, 50.0f);  // Camera positioned above the plane
    mAt = QVector3D(50.0f, 0.0f, 50.0f);     // Camera looks at the center of the plane
    mUp = QVector3D(0.0f, 0.0f, 1.0f);       // Vulkan uses Z-up

    init();  // Initialize the matrices

}

void Camera::init() {
    mProjectionMatrix.setToIdentity();  // Set the projection matrix to identity initially
    mViewMatrix.setToIdentity();        // Set the view matrix to identity initially
    setStaticPosition();  // Position the camera and set the view matrix
}

void Camera::perspective(int degrees, double aspect, double nearplane, double farplane) {
    mProjectionMatrix.setToIdentity();

    // Set a FOV of 60 degrees, adjust the aspect ratio to match the window size
    mProjectionMatrix.perspective(60.0f, aspect, 0.1f, 500.0f);  // Reduce far plane distance if necessary

}

void Camera::setStaticPosition() {
    // Position the camera above the plane
    float heightAbovePlane = 30.0f;  // Camera height above the plane (adjustable)
    mEye = QVector3D(25.0f, 50.0f, 25.0f);
    mAt = QVector3D(25.0f, 10.0f, 25.0f);

    // The "up" direction is along the Z-axis in Vulkan's Z-up coordinate system
    mUp = QVector3D(0.0f, 0.0f, 1.0f);  // The up direction should be along Z-axis (Vulkan convention)

    // Initially set the view matrix
    mViewMatrix.setToIdentity();
    mViewMatrix.lookAt(mEye, mAt, mUp);

    // Now translate the camera to center the view
    // Shift the camera right and up to center the plane

    qDebug() << "Camera Eye Position:" << mEye;
    qDebug() << "Camera Look At Position:" << mAt;

}

void Camera::translate(float dx, float dy, float dz) {
    // Translate the camera position manually (if needed for dynamic camera control)
    mEye += QVector3D(dx, dy, dz);
    mAt += QVector3D(dx, dy, dz);  // Keep the target in sync with the camera position
    mViewMatrix.setToIdentity();
    mViewMatrix.lookAt(mEye, mAt, mUp);  // Recalculate the view matrix after translation
}

void Camera::rotate(float angle, float x, float y, float z) {
    // Rotate the camera view (if needed for dynamic camera control)
    mViewMatrix.rotate(angle, x, y, z);  // Rotate around an axis (x, y, z)
}

QMatrix4x4 Camera::cMatrix() {
    // Combine the projection and view matrices to get the final camera matrix
    return mProjectionMatrix * mViewMatrix;
}

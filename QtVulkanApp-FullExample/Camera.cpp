#include "Camera.h"

Camera::Camera() {

    mEye = QVector3D(50.0f, 150.0f, 50.0f);  // Camera positioned above the plane
    mAt = QVector3D(50.0f, 0.0f, 50.0f);     // Camera looks at the center of the plane
    mUp = QVector3D(0.0f, 0.0f, 1.0f);
    init();
}

void Camera::init() {
    mProjectionMatrix.setToIdentity();  // Set the projection matrix to identity initially
    mViewMatrix.setToIdentity();        // Set the view matrix to identity initially
    setStaticPosition();
}

void Camera::perspective(int degrees, double aspect, double nearplane, double farplane) {
    mProjectionMatrix.setToIdentity();


    mProjectionMatrix.perspective(60.0f, aspect, 0.1f, 500.0f);

}

void Camera::setStaticPosition() {
    // Position the camera above the plane
    float heightAbovePlane = 30.0f;
    mEye = QVector3D(25.0f, 50.0f, 25.0f);
    mAt = QVector3D(25.0f, 10.0f, 25.0f);

    mUp = QVector3D(0.0f, 0.0f, 1.0f);

    // Initially set the view matrix
    mViewMatrix.setToIdentity();
    mViewMatrix.lookAt(mEye, mAt, mUp);

    qDebug() << "Camera Eye Position:" << mEye;
    qDebug() << "Camera Look At Position:" << mAt;

}

void Camera::translate(float dx, float dy, float dz) {

    mEye += QVector3D(dx, dy, dz);
    mAt += QVector3D(dx, dy, dz);
    mViewMatrix.setToIdentity();
    mViewMatrix.lookAt(mEye, mAt, mUp);
}

void Camera::rotate(float angle, float x, float y, float z) {
    mViewMatrix.rotate(angle, x, y, z);  // Rotate around an axis (x, y, z)
}

QMatrix4x4 Camera::cMatrix() {
    return mProjectionMatrix * mViewMatrix;
}

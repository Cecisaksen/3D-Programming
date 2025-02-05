#ifndef VKCAMERA_H
#define VKCAMERA_H
#include <QMatrix4x4>
#include <QVector3D>
class VkCamera
{
private:
    QVector3D mEye{0.0, 0.0, 9.0};  // Kameraposisjon
    QVector3D mAt{0.0, 0.0, 0.0};   // Kamerafokus
    QVector3D mUp{0.0, 1.0, 0.0};   // Kamera-orientering


    QMatrix4x4 mProjectionMatrix{};
    QMatrix4x4 mViewMatrix{};


public:
    VkCamera();
    ~VkCamera() { }


    void init();
    void perspective(int degrees, double aspect, double nearplane, double farplane);
    void lookAt(const QVector3D& eye, const QVector3D& at, const QVector3D& up);
    //void update();
    void translate(float dx, float dy, float dz);
    void rotate(float angle, float x, float y, float z); // Rotate the camera around a given axis
    QMatrix4x4 cMatrix();
    QMatrix4x4 getViewMatrix();
};

#endif // VKCAMERA_H

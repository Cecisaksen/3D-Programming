#include "VulkanWindow.h"
#include "VkCamera.h"
#include "RenderWindow.h"
#include <QKeyEvent>
#include <QDebug>


VulkanWindow::VulkanWindow()
{  }


QVulkanWindowRenderer* VulkanWindow::createRenderer()
{
    qDebug() << "createRenderer()";
    //Makes a new instance of the RenderWindow (our Renderer) class
    return mRenderWindow = new RenderWindow(this, true); // last true == try MSAA
}


void VulkanWindow::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Escape)
    {
        QCoreApplication::quit();       //Shuts down the whole program
    }

    if(event->key() == Qt::Key_T)
    {
        dynamic_cast<RenderWindow*>(mRenderWindow)->mCamera.translate(.0f, 0.0f, -1.0f);
    }

    if(event->key() == Qt::Key_R)
    {
        dynamic_cast<RenderWindow*>(mRenderWindow)->mCamera.translate(.0f, 0.0f, 1.0f);
    }

    if(event->key() == Qt::Key_A)
    {
        dynamic_cast<RenderWindow*>(mRenderWindow)->mCamera.translate(-0.5f, 0.0f, 0.0f);
    }

    if(event->key() == Qt::Key_D)
    {
        dynamic_cast<RenderWindow*>(mRenderWindow)->mCamera.translate(0.5f, 0.0f, 0.0f);
    }

    if(event->key() == Qt::Key_W)
    {
        dynamic_cast<RenderWindow*>(mRenderWindow)->mCamera.translate(.0f, 0.5f, 0.0f);
    }

    if(event->key() == Qt::Key_S)
    {
        dynamic_cast<RenderWindow*>(mRenderWindow)->mCamera.translate(.0f, -0.5f, 0.0f);
    }


}

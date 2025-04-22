#include "VulkanWindow.h"
#include "Renderer.h"
#include <QKeyEvent>
#include "VisualObject.h"
#include <vector>

VulkanWindow::VulkanWindow()
{
    mSelectedObject = nullptr;
}

QVulkanWindowRenderer* VulkanWindow::createRenderer()
{
    // Create a new instance of the RenderWindow (our Renderer) class
    mRenderWindow = new RenderWindow(this, true); // 'true' means MSAA is enabled
    return mRenderWindow;
}

void VulkanWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        QCoreApplication::quit(); // Quit
    }

    /********************************* Player Movement: *********************************/
    RenderWindow *rw = dynamic_cast<RenderWindow*>(mRenderWindow);
    if (!rw) {
        qWarning("RenderWindow is null");
        return;
    }


    // Cast mRenderWindow to RenderWindow* to access mPlayer
    RenderWindow* renderWindow = dynamic_cast<RenderWindow*>(mRenderWindow);
    if (renderWindow) {
        if (event->key() == Qt::Key_W) {
            renderWindow->mPlayer->move(0.0f, -1);  // Move player forward
        }
        if (event->key() == Qt::Key_S) {
            renderWindow->mPlayer->move(0.0f, 1);  // Move player backward
        }
        if (event->key() == Qt::Key_A) {
            renderWindow->mPlayer->move(1, 0.0f);  // Move player left
        }
        if (event->key() == Qt::Key_D) {
            renderWindow->mPlayer->move(-1, 0.0f);  // Move player right
        }

        renderWindow->mPlayer->update();
    } else {
        qDebug() << "RenderWindow cast failed!";
    }


    /********************************* Object Scaling: *********************************/
    {
        if (event->key() == Qt::Key_F) {
            qDebug("Scaling down object");
            dynamic_cast<RenderWindow*>(mRenderWindow)->mObjects.at(mIndex)->scale(0.9f);
        }
        if (event->key() == Qt::Key_G) {
            qDebug("Scaling up object");
            dynamic_cast<RenderWindow*>(mRenderWindow)->mObjects.at(mIndex)->scale(1.0f);
        }
    }

    /****************************** Camera Control: *******************************/
    {
        if (event->key() == Qt::Key_Y) {
            dynamic_cast<RenderWindow*>(mRenderWindow)->mCamera.translate(0.0f, 0.0f, 0.2f);
        }
        if (event->key() == Qt::Key_T) {
            dynamic_cast<RenderWindow*>(mRenderWindow)->mCamera.translate(0.0f, 0.0f, -0.2f);
        }
        if (event->key() == Qt::Key_R) {
            dynamic_cast<RenderWindow*>(mRenderWindow)->mCamera.rotate(45.0f, 0.0f, 0.0f, 1.0f);
        }
    }
}

#ifndef VULKANWINDOW_H
#define VULKANWINDOW_H

#include <QVulkanWindow>
#include "VisualObject.h"

/*The QVulkanWindow subclass reimplements the factory function QVulkanWindow::createRenderer().
This returns a new instance of the QVulkanWindowRenderer subclass.
A QVulkanWindow is a Vulkan-capable QWindow that manages a Vulkan device, a graphics queue,
a command pool and buffer, a depth-stencil image and a double-buffered FIFO swapchain, etc.
In order to be able to access various Vulkan resources via the window object,
a pointer to the window is passed and stored via the constructor.*/
class VulkanWindow : public QVulkanWindow
{
    Q_OBJECT

public:
    VulkanWindow();

    QVulkanWindowRenderer* createRenderer() override;
    QVulkanWindowRenderer* getRenderWindow() const { return mRenderWindow; }
    void setSelectedObject(VisualObject* object) { mSelectedObject = object; }

signals:
    void frameQueued(int colorValue);

protected:
    //The QVulkanWindow is a QWindow that we inherit from and have these functions
    // to capture mouse and keyboard.
    // Uncomment to use (you also have to make the definitions of
    // these functions in the cpp-file to use them of course!)
    //
    //    void mousePressEvent(QMouseEvent *event) override{}
    void keyPressEvent(QKeyEvent *event) override;
    //    void keyReleaseEvent(QKeyEvent *event) override{}
    //    void wheelEvent(QWheelEvent *event) override{}

    QVulkanWindowRenderer* mRenderWindow{ nullptr };
    VisualObject* mSelectedObject{ nullptr };
    int mIndex{0};




private:
    int mMouseXlast{0};
};
#endif // VULKANWINDOW_H

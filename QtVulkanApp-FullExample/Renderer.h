#ifndef RENDERER_H
#define RENDERER_H

#include <QVulkanWindow>
#include <vector>
#include <unordered_map>
#include "Camera.h"
#include "Player.h"
#include "TriangleSurface.h"
#include "VisualObject.h"

class Pickup;

class RenderWindow : public QVulkanWindowRenderer
{
public:
    RenderWindow(QVulkanWindow *w, bool msaa = false);

    //Initializes the Vulkan resources needed,
    // the buffers
    // vertex descriptions for the shaders
    // making the shaders, etc
    void initResources() override;

    //Set up resources - only MVP-matrix for now:
    void initSwapChainResources() override;

    //Empty for now - needed since we implement QVulkanWindowRenderer
    void releaseSwapChainResources() override;

    //Release Vulkan resources when program ends
    //Called by Qt
    void releaseResources() override;

    //Render the next frame
    void startNextFrame() override;

    //Get Vulkan info - just for fun
    void getVulkanHWInfo();

    std::vector<VisualObject*>& getObjects() { return mObjects; }
    std::unordered_map<std::string, VisualObject*>& getMap() { return mMap; }

protected:

    //Creates the Vulkan shader module from the precompiled shader files in .spv format
    VkShaderModule createShader(const QString &name);

	void setModelMatrix(QMatrix4x4 modelMatrix);

    //The ModelViewProjection MVP matrix
    QMatrix4x4 mProjectionMatrix;
    //Rotation angle of the triangle
    float mRotation{ 0.0f };

    //Vulkan resources:
    QVulkanWindow* mWindow{ nullptr };
    QVulkanDeviceFunctions *mDeviceFunctions{ nullptr };

    VkDeviceMemory mBufferMemory{ VK_NULL_HANDLE };
    VkBuffer mBuffer{ VK_NULL_HANDLE };
 
    VkDescriptorPool mDescriptorPool{ VK_NULL_HANDLE };
    VkDescriptorSetLayout mDescriptorSetLayout{ VK_NULL_HANDLE };
    VkDescriptorSet mDescriptorSet[QVulkanWindow::MAX_CONCURRENT_FRAME_COUNT]{ VK_NULL_HANDLE };

    VkPipelineCache mPipelineCache{ VK_NULL_HANDLE };
    VkPipelineLayout mPipelineLayout{ VK_NULL_HANDLE };
    VkPipeline mPipeline{ VK_NULL_HANDLE };
    VkPipelineLayout mPipelineLayout2{ VK_NULL_HANDLE };
    VkPipeline mPipeline2{ VK_NULL_HANDLE };

private:
    friend class VulkanWindow;
    Player* mPlayer;
    TriangleSurface mSurface;
    VisualObject mVisualObject;
    std::vector<VisualObject*> mObjects;
    std::vector<VisualObject*> mObjects2;

    Pickup* inHouse;
    TriangleSurface* surfaceOne;
    TriangleSurface* surfaceTwo;

    NPC* NPCOne;
    NPC* NPCTwo;

    class Door* door;

    std::vector<Pickup*> mPickup;
    bool doorTriggered = false;

    std::unordered_map<std::string, VisualObject*> mMap;    // alternativ container

    void createBuffer(VkDevice logicalDevice,
                      const VkDeviceSize uniAlign, VisualObject* visualObject,
                      VkBufferUsageFlags usage=VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);
    //VkBuffer& buffer,
    //VkDeviceMemory& bufferMemory) ;
    Camera mCamera;
    //VkDevice logicalDevice;
    //VkPipelineInputAssemblyStateCreateInfo ia;
    //VkGraphicsPipelineCreateInfo pipelineInfo;
};

#endif // RENDERER_H

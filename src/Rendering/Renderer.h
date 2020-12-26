#pragma once
#include "Framebuffer.h"

struct RenderSettings
{
    int width;
    int height;
    int spp;

};

class Renderer
{
public:
    Renderer();
    ~Renderer();

    void SetupRenderer(RenderSettings& desc);

    void RenderScene();

    void RenderUI();

private:
    RenderSettings mySettings;
    Framebuffer* tmpBuffer;
};


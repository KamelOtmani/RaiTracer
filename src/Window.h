#pragma once
#include "OpenGL/OpenGL.h"

class Window
{
public:
    Window();
    ~Window();

    // Initialize all the opengl stuff
    // return false if failed
    bool InitContext();

    void PollEvents();

    void UpdateWindow();

    void Terminate();

    GLFWwindow* getWindowHandle() { return handle; }
private:
    unsigned int m_Width = 1600;
    unsigned int m_Height = 900;
    
    GLFWwindow* handle;
};


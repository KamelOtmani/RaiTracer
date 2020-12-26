#pragma once
#include "OpenGL/OpenGL.h"
#include "Application.h"

class Window
{
public:
    Window();
    ~Window();

    // Initialize all the opengl stuff
    // return false if failed
    bool InitContext();

    void PollEvents();

    void StartFrame();

    void UpdateWindow();

    void EndFrame();

    void Terminate();

    GLFWwindow* getWindowHandle() { return handle; }
private:
    unsigned int m_Width = 1600;
    unsigned int m_Height = 900;
    
    GLFWwindow* handle;
    ApplicationLayer* m_AppLayer;
    //ImGuiLayer m_ImGuiLayer;
};


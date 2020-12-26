#include "Window.h"
#include <iostream>

Window::Window()
{
    handle = nullptr;
}

Window::~Window()
{
    delete m_AppLayer;
}

bool Window::InitContext()
{
    /* Initialize glfw */
    if (!glfwInit())
        std::cout << " COULDNT INIT GLFW" << std::endl;
        //return false;

    /* Create a windowed mode window and its OpenGL context */
    handle = glfwCreateWindow(m_Width, m_Height, "RaiTracer 2000X", NULL, NULL);
    if (!handle)
    {
        std::cout << " COULDNT CREATE CONTEXT" << std::endl;
        glfwTerminate();
        return false;
    }

    m_AppLayer = new ApplicationLayer(handle, 1600, 900);
    /* Make the window's context current */
    glfwMakeContextCurrent(handle);

    if (glewInit() != GLEW_OK)
    {
        std::cout << " ERROR GLEW INIT IS NOT OK" << std::endl;
    }
    
    // Attach Layers
    m_AppLayer->OnAttach();
    
    return true;


}


void Window::PollEvents()
{
    /* Poll for and process events */
    glfwPollEvents();
}

void Window::StartFrame()
{
    m_AppLayer->OnStartFrame();
}

void Window::UpdateWindow()
{
    m_AppLayer->OnUpdate();
    glfwSwapBuffers(handle);
}

void Window::EndFrame()
{
    m_AppLayer->OnEndFrame();
}

void Window::Terminate()
{
    m_AppLayer->OnDettach();

    glfwDestroyWindow(handle);
    glfwTerminate();
}

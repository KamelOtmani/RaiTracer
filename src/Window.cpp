#include "Window.h"
#include <iostream>

Window::Window()
{
    handle = nullptr;
}

Window::~Window()
{
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

    /* Make the window's context current */
    glfwMakeContextCurrent(handle);

    if (glewInit() != GLEW_OK)
    {
        std::cout << " ERROR GLEW INIT IS NOT OK" << std::endl;
    }
    return true;
}


void Window::PollEvents()
{
    /* Poll for and process events */
    glfwPollEvents();
}

void Window::UpdateWindow()
{
    glfwSwapBuffers(handle);
}

void Window::Terminate()
{
    glfwDestroyWindow(handle);
    glfwTerminate();
}

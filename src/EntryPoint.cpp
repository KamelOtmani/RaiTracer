#include <iostream>

//#include "RaiTracer.h"
#include "Window.h"
//#include "OpenGL/OpenGL.h"

#undef main
int main(int, char**)
{
#if 0


    GLFWwindow* handle;
    /* Initialize glfw */
    if (!glfwInit())
    {
        std::cout << " COULDNT INIT GLFW" << std::endl;
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    handle = glfwCreateWindow(1600, 900, "RaiTracer 2000X", NULL, NULL);
    if (!handle)
    {
        std::cout << " COULDNT CREATE CONTEXT" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(handle);

    if (glewInit() != GLEW_OK)
    {
        std::cout << " ERROR GLEW INIT IS NOT OK" << std::endl;
    }

    while (!glfwWindowShouldClose(handle))
    {
        glfwPollEvents();
        glClearColor(0.1f, 0.1f, 0.15f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(handle);
        glfwPollEvents();
    }
    glfwDestroyWindow(handle);
    glfwTerminate();
#endif // 0

#if 1


    Window sWindow;

    if (!sWindow.InitContext())
        return 0;

    // Attach ImGuiLayer
    // Attach Application Layer
    while (!glfwWindowShouldClose(sWindow.getWindowHandle()))
    {
        //sWindow.PollEvents();

        // Start Frame
        glClearColor(0.1f, 0.1f, 0.15f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        // Update Applicatgion Layer

        // Render ImguiLayer

        // End Frame
        sWindow.UpdateWindow();
        sWindow.PollEvents();
    }
    sWindow.Terminate();
#endif // 0
    return 0;
}
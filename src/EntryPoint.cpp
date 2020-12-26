#include <iostream>

#include "RaiTracer.h"
#include "Core/Window.h"

#undef main
int main(int, char**)
{

    Window sWindow;

    if (!sWindow.InitContext())
        return 0;

    // Attach ImGuiLayer
    // Attach Application Layer
    while (!glfwWindowShouldClose(sWindow.getWindowHandle()))
    {
        //sWindow.PollEvents();

        sWindow.StartFrame();
        glClearColor(0.1f, 0.1f, 0.15f, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        // Start Frame
        // Update Applicatgion Layer
        sWindow.UpdateWindow();
        sWindow.EndFrame();
        // End Frame
        sWindow.PollEvents();
    }
    sWindow.Terminate();

    return 0;
}
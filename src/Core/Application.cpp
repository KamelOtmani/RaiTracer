#include "Application.h"


ApplicationLayer::ApplicationLayer(GLFWwindow* window, int weight, int height)
{
    m_imGuiLayer = new ImGuiLayer(window, ImVec2((float)weight, (float)height));
    
}

ApplicationLayer ::~ApplicationLayer()
{
    delete m_imGuiLayer;
}

void ApplicationLayer::OnAttach()
{
    RenderSettings rDesc;
    rDesc.height = 380;
    rDesc.width = 640;
    rDesc.spp = 1;
    sRenderer.SetupRenderer(rDesc);
    m_imGuiLayer->Init();
}

void ApplicationLayer::OnStartFrame()
{
    m_imGuiLayer->StartFrame();
    bool show_app_dockspace = true;
    m_imGuiLayer->SetupDockspace(&show_app_dockspace);
    sRenderer.RenderUI();
}

void ApplicationLayer::OnUpdate()
{
    ImGui::ShowDemoWindow();
    m_imGuiLayer->Render();
}

void ApplicationLayer::OnEndFrame()
{
}

void ApplicationLayer::OnDettach()
{
    m_imGuiLayer->Shutdown();
}

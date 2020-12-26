#pragma once

#include "imGui/imgui.h"
#include "imGui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <GLFW\glfw3.h>


class ImGuiLayer 
{
public:
	ImGuiLayer();
	ImGuiLayer(GLFWwindow* window, ImVec2 DisplaySize);
	~ImGuiLayer();

	void Init();
	void StartFrame();
	void Render();
	void Shutdown();

	void SetupDockspace(bool* p_open);

	void SetContext(GLFWwindow* window) { m_window = window; }
	void SetDisplaySize(ImVec2 displaySize) { m_displaySize = displaySize; }

private:
	GLFWwindow* m_window;
	ImVec2 m_displaySize;
	
};

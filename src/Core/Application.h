#pragma once

#include "Layer.h"
#include "UI/ImGuiLayer.h"

class ApplicationLayer : public Layer
{
public:
	ApplicationLayer(GLFWwindow* window,int weight,int height);
	~ApplicationLayer();

	virtual void OnAttach()			override;
	virtual void OnStartFrame()		override;
	virtual void OnUpdate()			override;
	virtual void OnEndFrame()		override;
	virtual void OnDettach()		override;

private:

	ImGuiLayer* m_imGuiLayer;
};





#include "Renderer.h"
#include "Utility/Math.h"
#include <imGui\imgui.h>
#include "Utility/ImageUtility.h"
#include <iostream>


Renderer::Renderer()
{
}

Renderer::~Renderer()
{
	delete tmpBuffer;
}

void Renderer::SetupRenderer(RenderSettings& desc)
{
    mySettings = desc;
	tmpBuffer = new Framebuffer(mySettings.width, mySettings.height);
	RenderScene();
}

void Renderer::RenderScene()
{
	tmpBuffer->update(mySettings.width, mySettings.height);
    // RENDER
	for (int r = 0; r < tmpBuffer->height(); r++)
	{
		for (int c = 0; c < tmpBuffer->width(); c++)
		{
			
			float u = (c ) / (float)tmpBuffer->width();//+ Math::randf()
			float v = ((float)tmpBuffer->height() - r ) / (float)tmpBuffer->height();//+ Math::randf()
			//float v = ((float)tmpBuffer->width() + r + Math::randf()) / (float)tmpBuffer->height();
			auto p = vec3(u, v,0.f);
			tmpBuffer->set_pixel(r, c, p);
			
		}
	}
	std::cout << "DONE !" << std::endl;
	auto image = tmpBuffer->serialize();
	unsigned char* data;
	Utility::WriteImage(image, "Test.png", mySettings.width, mySettings.height, 3);
}

void Renderer::RenderUI()
{

	ImGui::Begin("Settings");
	if (ImGui::Button("RENDER"))
	{
		RenderScene();
	}
	ImGui::SliderInt("Width X", &mySettings.width, 1, 1024);

	
	ImGui::SliderInt("Height Y", &mySettings.height, 1, 1024);
		
	//ImGui::Text("DUMMY");
	ImGui::End();

}

#include "Framebuffer.h"


Framebuffer::Framebuffer(size_t width, size_t height, size_t channels) :
	m_width(width),
	m_height(height),
	m_channels(channels),
	data (new float[sizeof(float) * m_width * m_height * m_channels])
{
	printf("Created Framebuffer %i x %i x %i channels \n", width, height, channels);
}

Framebuffer::~Framebuffer()
{
	delete[] data;
}

void Framebuffer::set_pixel(int row, int col, vec3& pixel)
{
	//auto s = sizeof(float);
	const int idx = m_channels * (row * m_width + col);
	data[idx + 0] = pixel.r;
	data[idx + 1] = pixel.g;
	data[idx + 2] = pixel.b;
}

vec3 Framebuffer::get_pixel(int row, int col)
{
	const int idx = m_channels * (row * m_width + col);
	return vec3(data[idx + 0], data[idx + 1], data[idx + 2]);
}

void Framebuffer::update(size_t newWidth,size_t newHeight)
{
	m_width = newWidth;
	m_height = newHeight;
	delete[] data;
	data = new float[ m_width * m_height * m_channels];
}

uint8_t* Framebuffer::serialize()
{
	auto output = (uint8_t*)malloc(m_width * m_height * m_channels);
	for (size_t c = 0; c < m_width; c++)
	{
		for (size_t r = 0; r < m_height; r++)
		{
			const int idx = m_channels * (r * m_width + c);
			auto p = get_pixel(r, c);
			output[idx + 0] = (uint8_t)(p.r*255.f);
			output[idx + 1] = (uint8_t)(p.g*255.f);
			output[idx + 2] = (uint8_t)(p.b*255.f);
		}
	}
	return output;
}

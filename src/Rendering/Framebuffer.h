#pragma once

#include "Utility/Vector3.h"

class Framebuffer
{

public:
    Framebuffer(size_t width, size_t height, size_t channels = 3);

    ~Framebuffer();

    void set_pixel(int row, int col, vec3& pixel);

    vec3 get_pixel(int row, int col);

    void update(size_t newWidth,size_t newHeight);


    unsigned char* serialize();

    size_t width() const { return m_width; }
    size_t height() const { return m_height; }

    float* get_data() { return data; }

private:
    float* data;
    size_t m_width;
    size_t m_height;
    size_t m_channels;
};


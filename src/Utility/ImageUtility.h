#pragma once
#include <stdint.h>

namespace Utility
{
    unsigned char* LoadImage(const char* path, int& width, int& height, int& channels);
    void WriteImage(uint8_t* data, const char* path, int width, int height, int channels);
}
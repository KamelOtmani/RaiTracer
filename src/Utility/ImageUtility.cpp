#include "ImageUtility.h"


#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#endif // !STB_IMAGE_IMPLEMENTATION

#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"
#endif // !STB_IMAGE_IMPLEMENTATION

#ifndef STBI_MSC_SECURE_CRT
#define STBI_MSC_SECURE_CRT
#endif // !STBI_MSC_SECURE_CRT

unsigned char* Utility::LoadImage(const char* path, int& width, int& height, int& channels)
{
    unsigned char* img = stbi_load(path, &width, &height, &channels, 0);
    printf("SUCCSESFULLY LOADED IMAGE \n");
    if (img == NULL)
    {
        printf("ERROR LOADING IMAGE");
        return nullptr;
        //exit(0)
    }
    return img;
}

void Utility::WriteImage(uint8_t* data, const char* path, int width, int height, int channels)
{
    printf("SUCCSEZSLJLIDF SAVED IMAGE \n");
    stbi_write_png(path, width, height, channels, data, width * channels);
}

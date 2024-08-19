//
// Created by si1kn on 28/12/2023.
//

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

#define STB_IMAGE_IMPLEMENTATION

#include "ImageReader.h"

#define STB_IMAGE_IMPLEMENTATION



int *ImageReader::imageData(char *filePath) {
    int width, height, channels;
    unsigned char *image = stbi_load(filePath, &width, &height, &channels, 0);
    if (image == nullptr) {
        std::cerr << "Error: Unable to load the image." << std::endl;
        return nullptr;
    }

    int* imageArray = new int[width * height];

    int counter = 0;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Calculate the index for the current pixel
            int index = (y * width + x) * channels;

            // Access pixel values
            unsigned char red = image[index];
            unsigned char green = image[index + 1];
            unsigned char blue = image[index + 2];

            int r = static_cast<int>(red);
            int g = static_cast<int>(green);
            int b = static_cast<int>(blue);

            // Calculate the color value
            int colour = ((255 & 0xFF) << 24) |
                         ((r & 0xFF) << 16) |
                         ((g & 0xFF) << 8) |
                         ((b & 0xFF) << 0);

            // Store the color value in the image array
            imageArray[counter] = colour;
            counter++;
        }
    }

    // Free the loaded image data
    stbi_image_free(image);

    return imageArray;
}

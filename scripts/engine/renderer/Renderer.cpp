//
// Created by si1kn on 7/10/2023.
//


#include "Renderer.h"




//static ImageReader imageReader = ImageReader();

//
// int *grassWithPinkFlowers = imageReader.imageData(
//     R"(E:\New folder\clion-cmake-sdl2-template\assets\grassWithPinkFlower.png)");
// int *grassWithBlueFlowers = imageReader.imageData(
//     R"(E:\New folder\clion-cmake-sdl2-template\assets\grassWithBlueFlower.png)");
//
// int *water_LBC = imageReader.imageData(
//     R"(E:\New folder\clion-cmake-sdl2-template\assets\water\left_bottom_corner.png)");
// int *water_LTC = imageReader.imageData(
//     R"(E:\New folder\clion-cmake-sdl2-template\assets\water\left_top_corner.png)");
//
// int *water_RBC = imageReader.imageData(
//     R"(E:\New folder\clion-cmake-sdl2-template\assets\water\right_bottom_corner.png)");
//
// int *water_RTC = imageReader.imageData(
//     R"(E:\New folder\clion-cmake-sdl2-template\assets\water\right_top_corner.png)");
//
// int *water_C = imageReader.imageData(
//     R"(E:\New folder\clion-cmake-sdl2-template\assets\water\water_center.png)");
//
//
// int *fireball = imageReader.imageData(
//     R"(E:\New folder\clion-cmake-sdl2-template\assets\fireball.png)");
//
// int *grass = imageReader.imageData("E:\\New folder\\clion-cmake-sdl2-template\\assets\\grass\\grass_default.png");
// int *grass1 = imageReader.imageData("E:\\New folder\\clion-cmake-sdl2-template\\assets\\grass\\grass_1.png");
// int *grass2 = imageReader.imageData("E:\\New folder\\clion-cmake-sdl2-template\\assets\\grass\\grass_2.png");
// int *grass3 = imageReader.imageData("E:\\New folder\\clion-cmake-sdl2-template\\assets\\grass\\grass_3.png");
//

/*
void Renderer::reloadGrassTexture() {
    //  grass = imageReader.imageData("E:\\New folder\\clion-cmake-sdl2-template\\assets\\grass");
}
*/

/*
void Renderer::drawTile(int x, int y, TileType type, int state) {
    int width = 64, height = 64;

    height = SDL_min(height, getHeight()-y);


    if (x + 64 > getWidth()) {
        width -= (x + width) - getWidth();
        x = getWidth() - width;
    }

    long yOffset = (y * getWidth()) + x;


    int *pointer;

    switch (type) {
        case GRASS:
            pointer = grass1;
            break;
        case GRASS_WITH_PINK_FLOWER:
            pointer = grassWithPinkFlowers;
            break;
        case GRASS_WITH_BLUE_FLOWER:
            pointer = grassWithBlueFlowers;
            break;
        case WATER_LBC:
            pointer = water_LBC;
            break;
        //
        case WATER_LTC:
            pointer = water_LTC;
            break;
        //
        case WATER_RBC:
            pointer = water_RBC;
            break;
        case WATER_RTC:
            pointer = water_RTC;
            break;

        case WATER_CENTER:
            pointer = water_C;
            break;

        default: {
            pointer = grass;
        }
    }

    for (int i = 0; i < height; i++) {
        int startY = SDL_max(0, yOffset); // Ensure startY is not negative
        BGH_memcpyPixels(startY, &pointer[i * 64], width * sizeof(int));


        yOffset += getWidth();
    }
}
*/

void Renderer::renderBox(int x, int y, int width, int height, Colour colour) {
    int colourArr[width * height] = {};

    for (int i = 0; i < width * height; ++i) {
        colourArr[i] = colour.rgb;
    }

    height = SDL_min(height, getHeight()-y);
    if (x + 64 > getWidth()) {
        width -= (x + width) - getWidth();
        x = getWidth() - width;
    }
    long yOffset = (y * getWidth()) + x;
    for (int i = 0; i < height; i++) {
        int startY = SDL_max(0, yOffset); // Ensure startY is not negative
        BGH_memcpyPixels(startY, colourArr, width * sizeof(int));
        yOffset += getWidth();
    }
}


void Renderer::renderPlayer(int x, int y, int height, int width, int *array, Colour fontColour) {
    for (int xpos = 0; xpos < width; xpos++)
        for (int ypos = 0; ypos < height; ypos++) {
            int spacedX = xpos + x;
            int spacedY = ypos + y;
            int colour = array[ypos * width + xpos];

            if (colour != -3355444 && colour != -16777216 && colour != 0 && colour != -3487030 && colour != -3289651 &&
                colour != -5299281)
                setPixel(spacedX, spacedY, fontColour.rgb);
        }
}

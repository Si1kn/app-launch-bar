//
// Created by si1kn on 7/10/2023.
//

#ifndef HELLO_RENDERER_H
#define HELLO_RENDERER_H

#include "../Window.h"
#include "Colour.h"

#define STB_IMAGE_IMPLEMENTATION

#include "../../util/ImageReader.h"


class Renderer {
public:
    //  static void reloadGrassTexture();

    // static void drawTile(int x, int y, TileType type, int state);

    // static void renderPlayer(int x, int y);
    static void renderPlayer(int x, int y, int height, int width, int *array, Colour font_colour);

    static void renderBox(int x, int y, int width, int height, Colour colour);
};


#endif //HELLO_RENDERER_H

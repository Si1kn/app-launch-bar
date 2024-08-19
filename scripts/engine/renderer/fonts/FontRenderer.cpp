//
// Created by si1kn on 18/08/2024.
//

#include "FontRenderer.h"

#include <string.h>

#include "../Renderer.h"

static ImageReader imageReader = ImageReader();


int *allLetters = imageReader.imageData(
    R"(E:\New folder\clion-cmake-sdl2-template\assets\font\img.png)");



Colour fontColour = WHITE;

struct test {
    int pixels[55 * 60]{};
};

test ALL[55];


FontRenderer::FontRenderer(Colour fontColour1) {
    int arraySize = 0;
    fontColour = fontColour1;


    for (int height = 0; height < 3; ++height)
        for (int width = 0; width < 9; ++width) {
            for (int x = 0; x < 55; ++x)
                for (int t = 0; t < 60; ++t)
                    ALL[arraySize].pixels[t * 55 + x] = allLetters[(t + (60 * height)) * 500 + (x + (width * 55))];
            arraySize += 1;
        }
}

void FontRenderer::drawString(char *string1) {
    int len = strlen(string1);


    //  std::cout << "T";
    for (int i = 0; i < len; ++i) {
        char c = string1[i];
        int index = c - 'a';

        if (c != ' ')
            Renderer::renderPlayer(0 + (25 * i), 0, 60, 55, ALL[index].pixels, fontColour);
    }
}

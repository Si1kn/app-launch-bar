//
// Created by si1kn on 18/08/2024.
//

#ifndef FONTRENDERER_H
#define FONTRENDERER_H


#define STB_IMAGE_IMPLEMENTATION
#include "../../../util/ImageReader.h"


struct Colour;

class FontRenderer {
public:
    FontRenderer(Colour fontColour1);

    void drawString(char *string);
};


#endif //FONTRENDERER_H

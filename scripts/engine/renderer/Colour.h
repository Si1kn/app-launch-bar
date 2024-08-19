//
// Created by si1kn on 7/10/2023.
//

#ifndef HELLO_COLOUR_H
#define HELLO_COLOUR_H


const struct Colour {
    int r, g, b, a;
    int rgb;

    Colour(int r, int g, int b, int a) {
        rgb = ((a & 0xFF) << 24) |
              ((r & 0xFF) << 16) |
              ((g & 0xFF) << 8) |
              ((b & 0xFF) << 0);
    };


    Colour(int hex) {
        r = (hex >> 16) & 0xFF; // Extract the RR byte
        g = (hex >> 8) & 0xFF; // Extract the GG byte
        b = (hex) & 0xFF; // Extract the BB byte
        a = (hex >> 24) & 0xFF; // Extract the AA byte
    };


    // Extract the BB byte
} RED(255, 0, 0, 255), GREEN(0, 255, 0, 255), ORANGE(255, 165, 0, 255), WHITE(0, 0, 0, 255);

#endif //HELLO_COLOUR_H

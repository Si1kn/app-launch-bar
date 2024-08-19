//
// Created by si1kn on 23/09/2023.
//

#include <cmath>
#include <thread>
#include <iostream>
#include <SDL_keycode.h>

#include "../engine/Window.h"

#include "../engine/renderer/Renderer.h"
#include "../engine/renderer/fonts/FontRenderer.h"


bool *keys = new bool[256];


void setKeys(bool key) {
    for (int i = 0; i < 256; i++) {
        keys[i] = key;
    }
}

int *mousePos = new int[2];


Colour gray = Colour(59, 59, 59, 255);
Colour white = Colour(189, 189, 189, 255);
static FontRenderer font = FontRenderer(white);


char chars[100]{0};

int test,onlyChars = 0;

void render() {
    font.drawString(chars);
}

void keyEvent(int keyCode, bool pressed) {
    if (keyCode < 256)
        keys[keyCode] = pressed;


    if (pressed && ((keyCode > 96 && keyCode < 123) | keyCode == SDLK_SPACE)) {
        chars[test] = keyCode;
        test += 1;
    }

    if (pressed && keyCode == SDLK_BACKSPACE) {
        chars[test] = ' ';

        if (test > 0)
            test -= 1;
    }
}

void startGame() {
}


void tick(double delta) {
}

void constantMouse(int x, int y) {
}

void mouseClick(int x, int y, int button) {
}

void exit() {
}

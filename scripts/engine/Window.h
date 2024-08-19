//
// Created by si1kn on 23/09/2023.
//


#ifndef PROJECT_NAME_WINDOW_H
#define PROJECT_NAME_WINDOW_H

#include "SDL_stdinc.h"


static int pixels[960 * 72] = {0};

int *getPixelArray();


void setKeys(bool key);

void BGH_memcpyPixels(long v, int *t, unsigned long i);

void BGH_memsetPixels(long v, int t, unsigned long i);

void setPixel(int x, int y, int pixel);

void startGame();

void render();

void tick(double d);

void exit();

void keyEvent(int keyCode, bool pressed);

void mouseClick(int x, int y, int button);

void constantMouse(int x, int y);

int getWidth();

int getHeight();

#endif //PROJECT_NAME_WINDOW_H

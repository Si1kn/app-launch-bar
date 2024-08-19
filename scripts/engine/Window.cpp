#include <iostream>
#include "SDL.h"
#include "Window.h"
#include "SDL_shape.h"

#include <thread>

const int SCREEN_WIDTH = 960, SCREEN_HEIGHT = 72;

SDL_Window *createWindow();

int sdlInit();


void setPixel(int x, int y, int color) {
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
        pixels[y * getWidth() + x] = color;
    }
}


void BGH_memcpyPixels(long v, int *t, unsigned long i) {
    SDL_memcpy(pixels + v, t, i);
}

void BGH_memsetPixels(long v, int t, unsigned long i) {
    SDL_memset(pixels + v, t, i);
}


int main(int argc, char *args[]) {
    sdlInit();

    setKeys(false);

    SDL_Window *window = createWindow();
    SDL_SetWindowOpacity(window, 0.6f);


    bool quit = false;
    SDL_Event e;

    SDL_Surface *surface1 = SDL_GetWindowSurface(window);

    while (!quit) {
        if (SDL_PollEvent(&e) != 0)
            switch (e.type) {
                case SDL_KEYDOWN:
                    keyEvent((int) e.key.keysym.sym, true);
                    break;
                case SDL_KEYUP:
                    keyEvent((int) e.key.keysym.sym, false);

                    break;
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    mouseClick((int) e.button.x, (int) e.button.y, (int) e.button.button);
                    break;

                case SDL_MOUSEMOTION:
                    constantMouse((int) e.button.x, (int) e.button.y);
                    break;


                default:
                    break;
            };


        SDL_LockSurface(surface1);
        SDL_memset(pixels, 0, sizeof(pixels));
        render();
        SDL_memcpy(surface1->pixels, pixels, sizeof(Uint32) * SCREEN_WIDTH * SCREEN_HEIGHT);
        SDL_UnlockSurface(surface1);
        SDL_UpdateWindowSurface(window);
    }

    exit();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

int sdlInit() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    } else {
        return 0;
    }
}

SDL_Window *createWindow() {
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    auto width = DM.w;
    auto height = DM.h;


    SDL_Window *window = SDL_CreateWindow("SDL Pixel Array Example", width / 3, height / 7,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);


    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    } else {
        return window;
    }
}

int getWidth() {
    return SCREEN_WIDTH;
}


int getHeight() {
    return SCREEN_HEIGHT;
}

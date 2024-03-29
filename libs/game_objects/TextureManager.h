#pragma once

extern "C" {
#include <stdio.h>
#include <string.h>

#include "../../SDL2-2.0.10/include/SDL.h"
#include "../../SDL2-2.0.10/include/SDL_main.h"
}

class TextureManager {
public:
	SDL_Surface* sprite;
	void loadTexture(const char* fileName);
	void drawSurface(SDL_Surface* screen, int x, int y);
	void drawSurfaceLadder(SDL_Surface* screen, int xpos, int ypos, SDL_Rect dest);
};
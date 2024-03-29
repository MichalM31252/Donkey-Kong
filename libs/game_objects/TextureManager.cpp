extern "C" {
#include "./TextureManager.h"
}

void TextureManager::loadTexture(const char* fileName) {
	sprite = SDL_LoadBMP(fileName);
	if (sprite == NULL) {
		printf("SDL_LoadBMP error: %s\n", SDL_GetError());
	}
}

// draw a surface sprite on a surface screen in point (x, y)
// (x, y) is the center of sprite on screen
void TextureManager::drawSurface(SDL_Surface* screen, int xpos, int ypos) { // yeah there is the problem
	SDL_Rect dest;
	dest.x = xpos;
	dest.y = ypos;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
};

void TextureManager::drawSurfaceLadder(SDL_Surface* screen, int xpos, int ypos, SDL_Rect dest) { // not the best solution but works
	sprite->w = dest.w;
	sprite->h = dest.h;
	SDL_BlitSurface(sprite, NULL, screen, &dest); // it doesnt overwrite the original size of the image
};
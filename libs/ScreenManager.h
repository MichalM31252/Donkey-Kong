#pragma once

extern "C" {
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../SDL2-2.0.10/include/SDL.h"
#include "../SDL2-2.0.10/include/SDL_main.h"
#include "GameObject.h"
#include "Constants.h"
}

class ScreenManager {
	public:
		int tick1, tick2, frames;
		double deltaTime, worldTime, fpsTimer, fps;

		Uint32 black, green, red, blue, white;
		Uint32 ladderColor, platformColor;

		int rc;
		SDL_Surface* screen, * charset; // screen on which we will be drawing, charset is the bitmap with characters
		SDL_Texture* scrtex; // 
		SDL_Window* window; // widnows window
		SDL_Renderer* renderer; // we send here to render the screen

		void SDLCheck();
		void SDLCreateWindowAndRenderer();
		void setSDLHint();
		void setSDLRenderLogicalSize();
		void setSDLDefaultDrawColor();
		void setSDLWindowTitle();
		void setSDLCharset();
		void setSDLScreen();
		void setSDLTexture();

		void hideSDLCursor();
		void setSDLColorKey();

		void setColors();
		void drawOutlineOfTheBoard();
		void drawAdditionalInfo(double worldTime);
		void createSDL();

		void createFramerate();
		void handleFPSTimer();
		void handleDifferentComputers();
		void updateWorldTime();

		void serveNextFrame();

		static void loadTexture(GameObject* gameObject, const char* fileName); // Temporary solution

		void drawSurface(SDL_Surface* screen, GameObject* gameObject, int xpos, int ypos);
		void drawSurfaceLadder(SDL_Surface* screen, GameObject* ladder, int xpos, int ypos, SDL_Rect dest);
		void DrawString(SDL_Surface* screen, int x, int y, const char* text, SDL_Surface* charset);
		void DrawPixel(SDL_Surface* surface, int x, int y, Uint32 color);
		void DrawLine(SDL_Surface* screen, int x, int y, int l, int dx, int dy, Uint32 color);
		void DrawRectangle(SDL_Surface* screen, int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor);

		static void initGameObject(GameObject* gameObject, const char* fileName);
		void renderGameObject(GameObject* gameObject, SDL_Surface* screen);
		void renderLadder(GameObject* gameObject, SDL_Surface* screen);
};
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>

class Game_Driver
{

	public:
		bool initMainWindow();
		void closeMainWindow();
		void controlInput();
		void prepareScene(void);
		void presentScene(void);
		SDL_Texture* loadTexture(const char *imageFileName);

		void displayObject(SDL_Texture *texture, int x, int y);


		//The window we'll be rendering to
		SDL_Window* gWindow = NULL;

		//The surface contained by the window
		SDL_Surface* gScreenSurface = NULL;

		//The image we will load and show on the screen
		SDL_Surface* gHelloWorld = NULL;

		SDL_Renderer* gRenderer = NULL;

};


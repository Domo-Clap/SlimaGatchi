#include "Headers/Game_Driver.h"

int BaseWindowWidth = 640;
int BaseWindowHeight = 480;

bool Game_Driver::initMainWindow()
{
	int rendererFlags = SDL_RENDERER_ACCELERATED;

	bool success = true;

	if (SDL_Init( SDL_INIT_VIDEO ) < 0) {

		std::cout << "Error loading SDL! SDL could not initialize! \n\n Error: " << SDL_GetError() << std::endl;
		success = false;


	}
	else {

		gWindow = SDL_CreateWindow("SlimaGatchi! Base App", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, BaseWindowWidth, BaseWindowHeight, SDL_WINDOW_SHOWN);

		if (gWindow == NULL) {

			success = false;
			std::cout << "Error opening SDL window! SDL could not initialize window! \n\n Error: " << SDL_GetError() << std::endl;


		}
		else {

			SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

			// Creates a renderer on our main window 
			gRenderer = SDL_CreateRenderer(gWindow, -1, rendererFlags);

			if (gRenderer == NULL) {

				success = false;
				std::cout << "Error creating renderer! SDL could not initialize renderer in window! \n\n Error:" << SDL_GetError() << std::endl;

			}


		}

	}

	return success;
}

void Game_Driver::closeMainWindow()
{

	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();


}

void Game_Driver::controlInput()
{
	// SDL event used to determine when a user performs an action like input
	SDL_Event e;

	// Constantly searching for events to occurr
	while (SDL_PollEvent(&e)) {

		switch (e.type) {

		case SDL_QUIT:
			exit(0);
			break;

		default:
			break;

		}

	}

}

void Game_Driver::prepareScene(void)
{

	// Sets the background color of rendered on window
	SDL_SetRenderDrawColor(gRenderer, 96, 100, 225, 255);

	SDL_RenderClear(gRenderer);

}

void Game_Driver::presentScene(void)
{

	SDL_RenderPresent(gRenderer);

}


SDL_Texture* Game_Driver::loadTexture(const char* imageFileName)
{

	// Texture object
	SDL_Texture* texture;


	// Loads our image as a terxture: takes in the renderer, and the image file path we are using
	texture = IMG_LoadTexture(gRenderer, imageFileName);


	return texture;
}

void Game_Driver::displayObject(SDL_Texture* texture, int x, int y)
{

	SDL_Rect dest;

	dest.x = x;
	dest.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(gRenderer, texture, NULL, &dest);


}



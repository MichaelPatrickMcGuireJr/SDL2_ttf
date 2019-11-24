//Headers
#include "SDL.h"
#include "SDL_ttf.h"
//Start of the program
#include <iostream>

using namespace std;


int main(int argc, char* args[])
{
	int w = 150, h = 150;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("win 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL)
	{
		return 1;
	}
	if (TTF_Init() == -1)
	{
		return 1;
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	
	TTF_Font* font = TTF_OpenFont("FFF_Tusj.ttf",50);
	if (!font)
	{
		return -1;
	}
	SDL_Color textColor;
	textColor.r = 255; textColor.g = 0; textColor.b = 255;
	SDL_Surface *message = TTF_RenderText_Solid( font, "hello world!", textColor);
	SDL_Texture* text = NULL;
	text = SDL_CreateTextureFromSurface(renderer, message);
	SDL_QueryTexture(text, NULL, NULL, &w, &h);
	SDL_Rect textRect;
	textRect.x = 150; textRect.y = 150; textRect.w = w; textRect.h = h;

	SDL_RenderClear(renderer);
	
	SDL_RenderCopy(renderer, text, NULL, &textRect);

	SDL_RenderPresent(renderer);

	SDL_Delay(5000);
	cout << "done";

	return 0;
}



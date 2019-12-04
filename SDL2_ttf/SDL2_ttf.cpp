/*
 *   Author:  Michael McGuire
 *  Purpose:  SDL2, openning the direct media layer and using TTF to display font
 * Language:  c++
 */

// headers
#include "SDL.h"
#include "SDL_ttf.h"


int main(int argc, char* args[])
{
	// required to initialize SDL2
	SDL_Init(SDL_INIT_EVERYTHING);

	// create our window and the renderer to draw within the window
	SDL_Window* window = SDL_CreateWindow("win 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL)
	{
		return 1;
	}
	// set background color for the renderer
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	

	// placing text having standard ttf font
	if (TTF_Init() == -1)
	{
		return 1;
	}
	// size of text width and height
	int text_width = 150, text_height = 150;
	// loading TrueType Font from file
	TTF_Font* font = TTF_OpenFont("FFF_Tusj.ttf",50);
	if (!font)
	{
		return -1;
	}
	// creating a color pallete
	SDL_Color textColor;
	textColor.r = 255; textColor.g = 0; textColor.b = 255;
	// combining the font type, string value, and pallete onto a surface
	SDL_Surface* surface = TTF_RenderText_Solid( font, "hello world!", textColor);
	// use the renderer to place surface onto a texture (this procedure is an artifact from the original SDL, surfaces are mostly phased out in SDL2)
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &text_width, &text_height);
	// create a rectangle object to draw the texture on.  We position the rectangle, and then use the same sizes (width and height) as used in creating the font
	SDL_Rect rectangle;
	rectangle.x = 150; rectangle.y = 150; rectangle.w = text_width; rectangle.h = text_height;

	// clear the renderer
	SDL_RenderClear(renderer);
	// place texture on rectangle, put in renderer
	SDL_RenderCopy(renderer, texture, NULL, &rectangle);
	// place image on render into window
	SDL_RenderPresent(renderer);

	// wait 5 seconds
	SDL_Delay(5000);

	// remove resources to avoid memory leaks 
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);


	return 0;
}



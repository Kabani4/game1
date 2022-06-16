#include <SDL.h>
#include <iostream>


SDL_Window* window{ nullptr };
SDL_Surface* screenSurface{ nullptr };
SDL_Surface* picture{ nullptr };

int SDL_main()
{
	

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "Error sdl2 not found";
	else
	{
		window = SDL_CreateWindow("Text above page", SDL_WINDOWPOS_CENTERED_MASK, SDL_WINDOWPOS_CENTERED_MASK, 640, 480, SDL_WINDOW_OPENGL);
		screenSurface = SDL_GetWindowSurface(window);
		SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
		SDL_UpdateWindowSurface(window);
		SDL_Delay(3000);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
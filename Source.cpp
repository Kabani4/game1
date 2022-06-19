#include "game logic.h"


int SDL_main(int argc, char* argv[])
{
display main_win;
	main_win.INIT();
	while(main_win.isrunning)
	{
		
	SDL_SetRenderDrawColor(main_win.ren, 200, 200, 200, 255);
	SDL_RenderClear(main_win.ren);

	SDL_PollEvent(&main_win.ev);

	SDL_RenderPresent(main_win.ren);






	SDL_Delay(1000/main_win.get_fps());
	}
	
	
	main_win.DEINIT(0);
	return 0;
}



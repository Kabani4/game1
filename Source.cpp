#include "game logic.h"


int SDL_main(int argc, char* argv[])
{
Display main_win;
M_hunter main_character;
	main_win.INIT();
	while(main_win.isrunning)
	{
		
	SDL_SetRenderDrawColor(main_win.ren, 22, 192, 48, 255);
	SDL_RenderClear(main_win.ren);
	while (SDL_PollEvent(&main_win.ev))
	{
		main_character.MoveEvent(main_win.get_width(), main_win.get_height(), main_win.get_size(), main_win.get_fps(), main_win.ev);
	}
	main_character.MoveHunter(main_win.get_width(), main_win.get_height(), main_win.get_size(), main_win.get_fps());
	main_win.draw_map_game();
	main_win.draw_hunter(main_character.get_x(), main_character.get_y());

	SDL_RenderPresent(main_win.ren);

	SDL_Delay(1000/main_win.get_fps());
	}
	
	
	main_win.DEINIT(0);
	return 0;
}



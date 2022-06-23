#include "game logic.h"


int SDL_main(int argc, char* argv[])
{
	Display game_win{1};
	Display main_menu_win{0};
	M_hunter main_character{};

	game_win.INIT();

	while(GameLifetime)
	{
		SDL_SetRenderDrawColor(game_win.ren, 22, 192, 48, 255);
		SDL_RenderClear(game_win.ren);
		while (SDL_PollEvent(&game_win.ev))
		{
			main_character.MoveEvent(game_win.get_width(), game_win.get_height(), game_win.get_size(), game_win.get_fps(), game_win.ev);
		}
		main_character.MoveHunter(game_win.get_width(), game_win.get_height(), game_win.get_size(), game_win.get_fps());
		game_win.draw_map_game();
		game_win.draw_hunter(main_character.get_x(), main_character.get_y());

		SDL_RenderPresent(game_win.ren);

		SDL_Delay(1000/game_win.get_fps());
	}
	
	game_win.DEINIT(0);
	return 0;
}

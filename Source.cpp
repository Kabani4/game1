#include "game logic.h"


int SDL_main(int argc, char* argv[])
{
	MAIN_WINDOW God;
	Display game_win{ 1 };
	Display main_menu_win{ 0 };
	M_hunter main_character{};
	std::vector <Mushroom*> vector_mushrooms;

	Button Button_new_game{ 250, 50 };

	God.INIT();

	while(GameLifetime)
	{
		switch (Index_window)
		{
		case 0: 
			SDL_SetRenderDrawColor(God.ren, 108, 220, 100, 255);
			SDL_RenderClear(God.ren);
			//std::cout << God.get_width() + Button_new_game.GetWidth() / 2 << "   " << God.get_height() / (1 + 1) - Button_new_game.GetHeight() / 2 << std::endl;
			Button_new_game.SetCoord(God.get_width() / 2 - Button_new_game.GetWidth() / 2, God.get_height() / (1 + 1) - Button_new_game.GetHeight() / 2);
			Button_new_game.Draw_button(God.ren, 0, 0, 0, 255);
			while (SDL_PollEvent(&main_menu_win.ev))
			{
				//if (main_menu_win.ev.button.state == SDL_PRESSED) std::cout << main_menu_win.ev.motion.x << " " << main_menu_win.ev.motion.y << std::endl;
				if (Button_new_game.Button_click(main_menu_win.ev)) Index_window = 1;
			}
			break;
		case 1:
			SDL_SetRenderDrawColor(God.ren, 22, 192, 48, 255);
			SDL_RenderClear(God.ren);
			while (SDL_PollEvent(&game_win.ev))
			{
				main_character.MoveEvent(God.get_width(), God.get_height(), game_win.get_size(), game_win.get_fps(), game_win.ev);
			}
			main_character.MoveHunter(God.get_width(), God.get_height(), game_win.get_size(), game_win.get_fps());
			game_win.draw_map_game(God.ren, God.get_width(), God.get_height());
			game_win.draw_hunter(God.ren, main_character.get_x(), main_character.get_y());
			original_frame++;
			if (original_frame == Frame_to_spawn_mushroom)
			{
				Add_mush(main_character.get_x(), main_character.get_y(), &vector_mushrooms, God.get_width(), God.get_height(), game_win.get_size());
				original_frame = 0;
			}

			for (int i = 0; i < vector_mushrooms.size(); i++)
			{
				vector_mushrooms[i]->Delete_mush(main_character.get_x(), main_character.get_y(), &vector_mushrooms);
			}
			for (int i = 0; i < vector_mushrooms.size(); i++)
			{
				vector_mushrooms[i]->Draw_mush(God.ren);
			}
			SDL_RenderPresent(God.ren);
			SDL_Delay(1000 / game_win.get_fps());
			break;
		}
		/*SDL_SetRenderDrawColor(game_win.ren, 22, 192, 48, 255);
		SDL_RenderClear(game_win.ren);
		while (SDL_PollEvent(&game_win.ev))
		{
			main_character.MoveEvent(game_win.get_width(), game_win.get_height(), game_win.get_size(), game_win.get_fps(), game_win.ev);
		}
		main_character.MoveHunter(game_win.get_width(), game_win.get_height(), game_win.get_size(), game_win.get_fps());
		game_win.draw_map_game();
		game_win.draw_hunter(main_character.get_x(), main_character.get_y());
		original_frame++;
		if (original_frame == Frame_to_spawn_mushroom)
		{
			Add_mush(main_character.get_x(), main_character.get_y(), &vector_mushrooms, game_win.get_width(), game_win.get_height(), game_win.get_size());
			original_frame = 0;
		}
		
		for (int i = 0; i < vector_mushrooms.size(); i++)
		{
			vector_mushrooms[i]->Delete_mush(main_character.get_x(), main_character.get_y(), &vector_mushrooms);
		}
		for (int i=0; i < vector_mushrooms.size(); i++)
		{
			vector_mushrooms[i]->Draw_mush(game_win.ren);
		}*/
		
		
		
		
		SDL_RenderPresent(God.ren);
		SDL_Delay(1000/game_win.get_fps());
	}
	
	God.DEINIT(0);
	return 0;
}

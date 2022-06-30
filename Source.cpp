#include "game logic.h"


int SDL_main(int argc, char* argv[])
{
	MAIN_WINDOW God;
	Display game_win{ 1 };
	Display main_menu_win{ 0 };
	Display records_win{ 2 };
	Display information_win{ 3 };
	M_hunter main_character{};
	std::vector <Mushroom*> vector_mushrooms;

	Button Button_new_game{ 250, 50 };
	Button Button_exit{ 250, 50 };
	Button Button_records{ 250, 50 };
	Button Button_change_player{ 250, 50 };
	Button Button_information{ 250, 50 };

	int Mushroom_score = 0;

	God.INIT();
	srand(time(NULL));

	while(GameLifetime)
	{
		switch (Index_window)
		{
		case 0: 
			SDL_SetRenderDrawColor(God.ren, 108, 220, 100, 255);
			SDL_RenderClear(God.ren);
			Button_new_game.SetCoord(God.get_width() / 2 - Button_new_game.GetWidth() / 2, God.get_height() / (5 + 1) - Button_new_game.GetHeight() / 2);
			Button_new_game.Draw_button(God.ren, 0, 0, 0, 255);
			Button_exit.SetCoord(God.get_width() / 2 - Button_new_game.GetWidth() / 2, 5 * God.get_height() / (5 + 1) - Button_new_game.GetHeight() / 2);
			Button_exit.Draw_button(God.ren, 255, 0, 0, 255);
			Button_records.SetCoord(God.get_width() / 2 - Button_new_game.GetWidth() / 2, 3 * God.get_height() / (5 + 1) - Button_new_game.GetHeight() / 2);
			Button_records.Draw_button(God.ren, 20, 120, 120, 255);
			Button_change_player.SetCoord(God.get_width() / 2 - Button_new_game.GetWidth() / 2, 2 * God.get_height() / (5 + 1) - Button_new_game.GetHeight() / 2);
			Button_change_player.Draw_button(God.ren, 0, 0, 255, 255);
			Button_information.SetCoord(God.get_width() / 2 - Button_new_game.GetWidth() / 2, 4 * God.get_height() / (5 + 1) - Button_new_game.GetHeight() / 2);
			Button_information.Draw_button(God.ren, 0, 255, 0, 255);
			while (SDL_PollEvent(&main_menu_win.ev))
			{
				if (Button_new_game.Button_click(main_menu_win.ev)) {
					Index_window = 1;
					system("cls");
					std::cout << "Score " << Mushroom_score << std::endl;
				}
				if (Button_exit.Button_click(main_menu_win.ev)) GameLifetime = false;
			}
			break;
		case 1:
			SDL_SetRenderDrawColor(God.ren, 22, 192, 48, 255);
			SDL_RenderClear(God.ren);
			while (SDL_PollEvent(&game_win.ev))
			{
				if (game_win.ev.type == SDL_KEYDOWN)
					if (game_win.ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE && RunGame)
						RunGame = false;
					else if (game_win.ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE && !RunGame)
						RunGame = true;
				main_character.MoveEvent(God.get_width(), God.get_height(), game_win.get_size(), game_win.get_fps(), game_win.ev, RunGame);
			}
			if (RunGame)
				main_character.MoveHunter(God.get_width(), God.get_height(), game_win.get_size(), game_win.get_fps());
			game_win.draw_map_game(God.ren, God.get_width(), God.get_height());
			game_win.draw_hunter(God.ren, main_character.get_x(), main_character.get_y());
			if (RunGame) {
				original_frame++;
				if (original_frame == Frame_to_spawn_mushroom)
				{
					Add_mush(main_character.get_x(), main_character.get_y(), &vector_mushrooms, God.get_width(), God.get_height(), game_win.get_size());
					original_frame = 0;
				}

				for (int i = 0; i < vector_mushrooms.size(); i++)
				{
					if (vector_mushrooms[i]->Delete_mush(main_character.get_x(), main_character.get_y(), &vector_mushrooms))
					{
						Mushroom_score += 1;
						system("cls");
						std::cout << "Score " << Mushroom_score << std::endl;
					}

				}
			}
			for (int i = 0; i < vector_mushrooms.size(); i++)
			{
				vector_mushrooms[i]->Draw_mush(God.ren);
			}
			break;
		}
		
		SDL_RenderPresent(God.ren);
		switch (Index_window)
		{
		case 0: SDL_Delay(1000 / main_menu_win.get_fps());
			break;
		case 1: SDL_Delay(1000 / game_win.get_fps());
			break;
		}
	}
	
	God.DEINIT(0);
	return 0;
}

#pragma once

extern "C" {
#include "../SDL2-2.0.10/include/SDL.h"
#include "../SDL2-2.0.10/include/SDL_main.h"
#include "./game_screen/ScreenManager.h"
#include "./game_objects/dynamic_game_objects/DynamicGameObject.h"
#include "./game_objects/dynamic_game_objects/dynamic_game_object_child/Player.h"
#include "./game_events/EventManager.h"
#include "./Platform.h"
#include "./PlatformHolder.h"
#include "./LadderHolder.h"
}

class Game {
	public:
		// logic
		int tick1, tick2, frames;
		double deltaTime, worldTime, fpsTimer, fps;
		GameObject *donkeyKong;
		Player* player;
		PlatformHolder* platformHolder;
		LadderHolder* ladderHolder;


		// Game(); Constructor NEEDED ADD DEFAULT VALUES
		void initGame();

		void setUpFramerate();
		void setUpGameObjects(SDL_Surface* screen);
		void handleFPSTimer();
		void handleDifferentComputers();
		void updateWorldTime();
		
		void setUpRound(ScreenManager& screenManager);
		void handleRound(ScreenManager& screenManager);
		void handleCurrentRound(ScreenManager& screenManager, EventManager& eventHandler, int* startAnotherRound);

		void closeGame();
		void closeGame(ScreenManager& screenManager);
};
#pragma once
#include "./PhysicsManager.h"
#include "./game_events/CollisionManager.h"
#include "./GameObjectContainer.h"

#include "./game_screen/ScreenManager.h" // temporary fix

class GameObjectFactory {
public:
	GameObjectContainer* gameObjectContainer;
	CollisionManager* collisionManager;

	GameObjectFactory();

	void createPlayer();
	void createDonkeyKong();
	void createPrincess();

	void createPlatforms1();
	void createLadders1();
	void createPlatforms2();
	void createLadders2();
	void createPlatforms3();
	void createLadders3();
	void createBarrels();

	void createBoard(int boardId);

	~GameObjectFactory();
};
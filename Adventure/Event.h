#pragma once
#include <iostream>
#include "Enemy.h"
#include "Player.h"

class Event
{
private:
	int numOfEvents;
	Enemy* baseEnemy;

public:
	Event();
	~Event();
	Enemy* GenerateEnemy(Player& p, int enemyID);
	void GenerateEvent(Player& p);
	void EnemyEncounter(Player& p);
	void PuzzleEncounter(Player& p);
};


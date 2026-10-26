#pragma once
#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Event.h"
#include "Enemy.h"


class Game
{
private:
	Player player;
	Enemy* enemy;
	int choice;
	bool playing;

public:
	Game();
	virtual ~Game();
	void InitGame();
	void MainMenu();

	void SavePlayer();
	void LoadPlayer();
	void NewPlayer();
	void NewEnemy();
	void PrintPlayerStats();

	void newEvent();

	void SkillUp();

	bool GetPlaying();
};


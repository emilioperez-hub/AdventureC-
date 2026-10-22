#include "Event.h"

Event::Event()
{
}

Event::~Event()
{
}

void Event::GenerateEvent(Player& p)
{
	srand(static_cast<unsigned int>(time(0)));
	int i = rand() % 10;
	if (i < 10)
	{
		std::cout << "Enemy Encounter" << std::endl;
	}
	else if (1 < 7)
	{
		std::cout << "Puzzle Encounter" << std::endl;
	}
	else
	{
		std::cout << "Keep Traveling..." << std::endl;
	}
}

void Event::EnemyEncounter(Player& p)
{
	std::system("cls");
	int choice = 0;
	bool playerDefeated = false;
	bool enemyDefeated = false;
	bool playerTurn = false;
	bool escape = false;
	bool playerDefending = false;
	int firstTurn = rand() % 100 + 1;
	if (firstTurn >= 50 - p.GetLuck())
	{
		playerTurn = true;
	}
	else
	{
		playerTurn = false;
	}
	std::cout << "-----New Enemy Encounter-----" << std::endl;

	int level = p.GetLevel();
	int hp = level * 10;
	int damageMin = rand() % level + 1;
	int damageMax = rand() % level * 2;
	int currentDamage = rand() / (damageMax - damageMin + 1);
	int defence = rand() % level;
	int exp = level * 10;
	baseEnemy = new Enemy("", level, hp, currentDamage, defence, exp);
	while (!playerTurn || !enemyDefeated || !escape)
	{
		if (playerTurn)
		{
			std::cout << "Choose your action: " << std::endl;
			std::cout << "1: attack" << std::endl;
			std::cout << "2: Defend" << std::endl;
			std::cout << "3: " << std::endl;
			std::cout << "4: " << std::endl;
			std::cout << "0: escape" << std::endl;

		}
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			int scapeRand = (rand() % 100);
			if (scapeRand > 25)
			{
				std::cout << "Escaped...." << std::endl;
				escape = true;
			}
			break;
		case 1:
			std::system("cls");
			int attackRoll = rand() % 100 + 1;
			if (attackRoll > (50 - p.);
			{
				std::cout << "Player hit Enemy" << std::endl;
				baseEnemy->TakeDamage(p.DoDamage())
			}
			break;
		case 2:

			break;

		case 3:
			p.PrintPlayerStats();
			break;
		case 4:
			baseEnemy->PrintStats();
			break;
		default:
			std::cout << "invalid Option" << std::endl;
			break;

		}
		playerTurn = false;
		if (playerDefending)
	}
	else
	{
		std::cout << "--------Enemy Turn---------" << std::endl;
		if (!baseEnemy->IsAlive())
		{
			enemyDefeated = true;
			std::cout << "Enemy hit Player" << std::endl;
		}
	}
	}
}

void Event::PuzzleEncounter(Player& p)
{
}

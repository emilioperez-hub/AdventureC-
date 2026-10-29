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
		EnemyEncounter(p);
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
	std::string n[3] = { "GOD", "JESUS", "PEDRO" };
	int level = p.GetLevel();
	int hp = level * 10;
	int damage = rand() % p.GetDamageMin() + 1;
	int defence = rand() % level;
	int exp = level * 10;
	int randName = rand() % 3;
	switch (randName)
	{
	case 0:
		level = p.GetLevel() + 6;
		hp = level * 13;
		damage = rand() % p.GetDamageMin() + 6 + 3;
		defence = rand() % level + 2;
		exp = level * 10;
		break;
	case 1:
		level = p.GetLevel() + 6;
		hp = level * 13;
		damage = rand() % p.GetDamageMin() + 6 + 3;
		defence = rand() % level + 2;
		exp = level * 10;
		break;
	case 2:
		level = p.GetLevel() + 6;
		hp = level * 13;
		damage = rand() % p.GetDamageMin() + 6 + 3;
		defence = rand() % level + 2;
		exp = level * 10;
		break;
	default:
		break;
	}
	baseEnemy = new Enemy(n[randName], level, hp, damage, defence, exp);
	int attackRoll = 0;
	int defenceRoll = 0;
	int escapeRand = 0;
	while (!playerDefeated && !enemyDefeated && !escape)
	{
		if (playerTurn)
		{
			std::cout << "You have encounterer GOD." << std::endl;
			std::cout << "Choose your action: " << std::endl;
			std::cout << "1: attack" << std::endl;
			std::cout << "2: Defend" << std::endl;
			std::cout << "3: Character Sheet" << std::endl;
			std::cout << "0: escape" << std::endl;


			std::cin >> choice;
			switch (choice)
			{
			case 0:
				if (escapeRand > 25)
				{
					std::cout << "Escaped...." << std::endl;
					escape = true;
				}
				break;
			case 1:
				std::system("cls");
				if (attackRoll > (50 - p.GetDexterity()))
				{
					std::cout << "Player hit Enemy" << std::endl;
					baseEnemy->TakeDamage(p.DoDamage());
				}
				break;
			case 2:
				if (defenceRoll > 50 - p.DoDamage())
				{
					std::cout << "Player is defending" << std::endl;
				}
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
		}
		if (playerDefending)
		{
		}
		else
		{
			std::cout << "--------Enemy Turn---------" << std::endl;
			if (!baseEnemy->IsAlive())
			{
				enemyDefeated = true;
				std::cout << "Enemy hit Player" << std::endl;
			}
			playerTurn = true;
		}
	}
}

void Event::PuzzleEncounter(Player& p)
{

}

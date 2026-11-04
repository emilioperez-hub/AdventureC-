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
	else if (i < 7)
	{
		std::cout << "Puzzle Encounter" << std::endl;
		PuzzleEncounter(p);
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
		level = p.GetLevel() * 15;
		hp = level * 100;
		damage = rand() % p.GetDamageMin() * 10 + 10;
		defence = rand() % level * 10;
		exp = level * 1000;
		break;
	case 1:
		level = p.GetLevel() * 10;
		hp = level * 50;
		damage = rand() % p.GetDamageMin() * 5 + 10;
		defence = rand() % level * 5;
		exp = level * 100;
		break;
	case 2:
		level = p.GetLevel() * 5;
		hp = level * 25;
		damage = rand() % p.GetDamageMin() * 2 + 10;
		defence = rand() % level + 2;
		exp = level * 10;
		break;
	default:
		break;
	}
	baseEnemy = new Enemy(n[randName], level, hp, damage, defence, exp);
	int attackRoll = rand() % 100 + 1;
	int defenceRoll = rand() % 100 + 1;
	int escapeRand = rand() % 100 + 1;
	while (!playerDefeated && !enemyDefeated && !escape)
	{
		if (playerTurn)
		{
			std::cout << "You have encountered: " << n[randName] << std::endl;
			std::cout << "---------Your Turn---------" << std::endl;
			std::cout << "Choose your action: " << std::endl;
			std::cout << "1: Attack" << std::endl;
			std::cout << "2: Defend" << std::endl;
			std::cout << "3: Character Sheet" << std::endl;
			std::cout << "4: Enemy Sheet" << std::endl;
			std::cout << "0: Escape" << std::endl;


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
					playerDefending = true;
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
		int GODdamage = rand() % p.GetDamageMin() * 10 + 10;
		int Jdamage = rand() % p.GetDamageMin() * 5 + 10;
		int Pdamage = rand() % p.GetDamageMin() * 2 + 10;
		if (playerDefending)
		{
			if (randName == 1)
			{
				p.TakeDamage(GODdamage - (p.GetLevel() + p.GetLuck()));
			}
			else if (randName == 2)
			{
				p.TakeDamage(Jdamage - (p.GetLevel() + p.GetLuck()));

			}
			else
			{
				p.TakeDamage(Pdamage - (p.GetLevel() + p.GetLuck()));

			}
			playerDefending = false;
		}
		else
		{
			std::cout << "--------Enemy Turn---------" << std::endl;

			if (!baseEnemy->IsAlive())
			{
				enemyDefeated = true;
				std::cout << "Enemy hit Player" << std::endl;
			}
			switch (randName)
			{
			case 0:
				p.TakeDamage(GODdamage);
				std::cout << "Enemy hit player" << std::endl;
				break;
			case 1:
				p.TakeDamage(Jdamage);
				std::cout << "Enemy hit player" << std::endl;
				break;
			case 2:
				break;
				std::cout << "Enemy hit player" << std::endl;
				p.TakeDamage(Pdamage);
			default:
				break;
			}
			playerTurn = true;
		}
	}
	if (p.GetHP() <= 0)
	{
		playerDefeated = true;
	}
	else
	{
		playerDefeated = false;
	}
	
	if (playerDefeated)
	{
		std::cout << "You have been defeated by: " << n[randName] << std::endl;
	}
	else if (enemyDefeated)
	{
		std::cout << "You have defeated: " << n[randName] << std::endl;
		p.SetExp(p.GetExp() + baseEnemy->GetExp());
		p.LevelUp();
	}
	else if (escape)
	{
		std::cout << "You have escaped" << std::endl;
	}
}

void Event::PuzzleEncounter(Player& p)
{

}

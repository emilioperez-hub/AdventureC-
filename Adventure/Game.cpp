#include "Game.h"

Game::Game()
{
	this->playing = true;
}

Game::~Game()
{
}

void Game::InitGame() //Start() en Unity
{
	std::cout << "Starting the Game" << std::endl;
	NewPlayer();
}

void Game::MainMenu()
{
	std::cout << "-------MAIN MENU-------" << std::endl;
	std::cout << " 0: Quit Game" << std::endl;
	std::cout << " 1: Player Stats" << std::endl;
	std::cout << " 2: Enemy Stats" << std::endl;

	std::cout << " Enter Choice" << std::endl;
	std::cin >> choice;

	switch (choice)
	{
	case 0:
		this->playing = false;
		break;
	case 1:
		PrintPlayerStats();
		break;
	case 2:
		NewEnemy();
		break;
	default:
		std::cout << "Invalid Option" << std::endl;
		break;
	}
}

void Game::SavePlayer()
{
}

void Game::LoadPlayer()
{
}

void Game::NewPlayer()
{
	player.InitPlayer("Icazador");
}

void Game::NewEnemy()
{
	srand(static_cast<unsigned int>(time(0)));
	std::string name = "Goblin";
	int level = (rand() % 10);
	int hp = (rand() % 10);
	int xp = (rand() % 2);
	int damage = (rand() % 10);
	int defence = (rand() % 10);
	enemy = new Enemy(name, level, hp, damage, defence, xp);
	enemy->PrintEnemyStats();
}

void Game::PrintPlayerStats()
{
	player.PrintPlayerStats();
}

bool Game::GetPlaying()
{
	return this->playing;
}

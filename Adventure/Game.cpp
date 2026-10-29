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
	std::cout << " 2: New Event" << std::endl;
	std::cout << " 3: Enemy Stats" << std::endl;
	std::cout << " 4: Level up" << std::endl;
	std::cout << " 5: skill up" << std::endl;
	std::cout << " 6: save Player" << std::endl;
	std::cout << " 7: load Player" << std::endl;

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
		newEvent();
		break;
	case 3:
		NewEnemy();
		break;
	case 4:
		player.LevelUp();
		break;
	case 5:
		SkillUp();
		break;
	case 6:
		player.SaveStats();
		break;
	case 7:
		LoadPlayer();
		break;
	default:
		std::cout << "Invalid Option" << std::endl;
		break;
	}
}

void Game::SavePlayer()
{
	std::string PlayerFile;
	std::ofstream outFile(PlayerFile);
	if (outFile.is_open())
		outFile << player.SaveStats() << " ";
	else
		std::cout << "Cant Save Game :(" << std::endl;
	outFile.close();
	std::cout << "Game Saved :)" << std::endl;
}

void Game::LoadPlayer()
{
	std::string PlayerFile = "savePlayer.txt";
	player.LoadSavedStats(PlayerFile);
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

void Game::newEvent()
{
	Event e;
	e.GenerateEvent(player);
}

void Game::SkillUp()
{
	while(player.GetSkillPoints() > 0)
	{
		std::cout << "You have " << player.GetSkillPoints() << " skill points to spend." << std::endl;
		std::cout << "1: Strength" << std::endl;
		std::cout << "2: Agility" << std::endl;
		std::cout << "3: Dexterity" << std::endl;
		std::cout << "4: Intelligence" << std::endl;
		std::cout << "5: Luck" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			player.SetStrength(player.GetStrength() + 1);
			player.SetSkillPoints(player.GetSkillPoints() - 1);
			break;
		case 2:
			player.SetAgility(player.GetAgility() + 1);
			player.SetSkillPoints(player.GetSkillPoints() - 1);
			break;
		case 3:
			player.SetDexterity(player.GetDexterity() + 1);
			player.SetSkillPoints(player.GetSkillPoints() - 1);
			break;
		case 4:
			player.SetIntelligence(player.GetIntelligence() + 1);
			player.SetSkillPoints(player.GetSkillPoints() - 1);
			break;
		case 5:
			player.SetLuck(player.GetLuck() + 1);
			player.SetSkillPoints(player.GetSkillPoints() - 1);
			break;
		case 0:
			return;
		default:
			std::cout << "Invalid Option" << std::endl;
			break;
		}
	}
}

bool Game::GetPlaying()
{
	return this->playing;
}

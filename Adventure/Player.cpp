#include "Player.h"

Player::Player() :Character()
{
	this->strength = 5;
	this->agility = 5;
	this->dexterity = 5;
	this->intelligence = 5;
	this->luck = 5;
}

Player::~Player()
{
}

void Player::InitPlayer(std::string name)
{
	InitCharacter(name);
	SetLevel(1);
	SetExp(0);
	SetHP((this->intelligence * 2) / (this->dexterity -3));
	SetDamageMin(this->strength - 2);
	SetDamageMax(this->strength * 2);
	SetDefence((this->agility * 2) / (this->luck -3));

}

void Player::PrintPlayerStats()
{
	PrintStats();
	std::cout << "--------------------" << std::endl;
	std::cout << "Strength: " << this->strength << std::endl;
	std::cout << "Agility: " << this->agility << std::endl;
	std::cout << "Dexterity: " << this->dexterity << std::endl;
	std::cout << "Intelligence: " << this->intelligence << std::endl;
	std::cout << "Luck: " << this->luck << std::endl;
}

void Player::LevelUp()
{
	while (GetExp() >= MaxXp)
	{
		SetLevel(GetLevel() + 1);
		SetExp(GetExp() - MaxXp);
		MaxXp = GetLevel() * 10;
		skillpoints++;
		std::cout << "You leveled up to level: " << GetLevel() << "!" << std::endl;
	}
}

void Player::AddStats(int stat, int value)
{
	if (skillpoints < value)
	{
		std::cout << "You don't have enough skill points." << std::endl;
	}
	else
	{
		switch (stat)
		{
		case 1:
			this->strength += value;
			skillpoints -= value;
			updateStats();
			break;
		case 2:
			this->agility += value;
			skillpoints -= value;
			updateStats();
			break;
		case 3:
			this->intelligence += value;
			skillpoints -= value;
			updateStats();
			break;
		case 4:
			this->luck += value;
			skillpoints -= value;
			updateStats();
			break;
		case 5:
			this->dexterity += value;
			skillpoints -= value;
			updateStats();
			break;
		default:
			std::cout << "This stat does not exist." << std::endl;
			break;
		}
	}
}

void Player::updateStats()
{
	SetHP((this->intelligence * 2) / (this->dexterity - 3));
	SetDamageMin(this->strength - 2);
	SetDamageMax(this->strength * 2);
	SetDefence((this->agility * 2) / (this->luck - 3));
}


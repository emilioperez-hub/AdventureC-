#pragma once
#include "Character.h"
class Player :
	public Character
{
private:
	int strength;
	int agility;
	int dexterity;
	int intelligence;
	int luck;

public:
	Player();
	~Player();
	void InitPlayer(std::string name);
	void PrintPlayerStats();

	//Gets
	int GetStrength() { return strength; }
	int GetAgility() { return agility; }
	int GetDexterity() { return dexterity; }
	int GetIntelligence() { return intelligence; }
	int GetLuck() { return luck; }


	//Sets
	void SetStrength(int s) { strength  = s;}
	void SetAgility(int a) {  agility = a; }
	void SetDexterity(int d) { dexterity = d; }
	void SetIntelligence(int intel) { intelligence = intel; }
	void SetLuck(int l) { luck = l; }
};


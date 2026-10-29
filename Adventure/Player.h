#pragma once
#include <string>
#include <fstream>
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

	int MaxXp;
	int skillpoints;

public:
	Player();
	~Player();
	void InitPlayer(std::string name);
	void PrintPlayerStats();
	void LevelUp();
	void AddStats(int stat, int value);
	void updateStats();
	std::string SaveStats();
	void LoadSavedStats(const std::string& filename);

	//Gets
	int GetStrength() { return strength; }
	int GetAgility() { return agility; }
	int GetDexterity() { return dexterity; }
	int GetIntelligence() { return intelligence; }
	int GetLuck() { return luck; }
	int GetSkillPoints() { return skillpoints; }


	//Sets
	void SetStrength(int s) { strength  = s;}
	void SetAgility(int a) {  agility = a; }
	void SetDexterity(int d) { dexterity = d; }
	void SetIntelligence(int intel) { intelligence = intel; }
	void SetLuck(int l) { luck = l; }
	void SetSkillPoints(int sp) { skillpoints = sp; }
};


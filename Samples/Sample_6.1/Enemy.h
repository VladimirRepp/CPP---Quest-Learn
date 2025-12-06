#pragma once
#include <iostream>
#include <string>

using namespace std;

// Предварительное объявление класса Player
class Player;

class Enemy
{
private:
	string type;
	int health;
	int damage;
	int level;

public:
	Enemy(string enemy_type, int enemy_health,
		int enemy_damage, int enemy_level);

	void Attack(Player& targer);
	void PrintStats();
	void Heal(int amount);
	void TakeDamage(int damage);
	bool IsAlive();
};


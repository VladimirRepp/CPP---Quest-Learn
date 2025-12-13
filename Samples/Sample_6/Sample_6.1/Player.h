#pragma once

#include <iostream>
#include <string>

using namespace std;

// Предварительное объявление класса Enemy
class Enemy;

// Класс - Игрок 
class Player
{
	// Закрый спецификатор доступа 
private:
	// Поля класса 
	// Поле - это данные внутри класса 
	string name;
	int health;
	int damage;
	int level;

	// Открытый спецификатор доступа 
public:
	// Методы класса 
	// Метод - это функция внутри класса 
	Player(string player_name, int player_health,
		int player_damage, int player_level); // конструктор класса 

	void Attack(Enemy& target);
	void PrintStats();
	void Heal(int amount);
	void TakeDamage(int damage);
	bool IsAlive();
};


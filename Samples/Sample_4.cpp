#include <iostream>
#include <Windows.h>
using namespace std;

// возвращаемый_тип_данных название_функции (аргументы)
// { - начало тела функции 
// ... что то в функции 
// } - конец тела функции

// Задание: Создай функцию для лечения героя.
// heal - название функции, по названию просходит вызов функции 
// int -  тип возвращаемого значение 
// (...) - в скобках указываем что приходит в функцию, 
// может ничего не указывать или указать какие то параметры (аргументы)
int heal(int current_health, int potion_power, int max_health = 100)
{
	// current_health - текущее здоровье 
	// potion_power - количестов здоровья лечения от зелья 
	// max_health - максимальное количество здоровья 

	current_health += potion_power;

	if (current_health > max_health)
		return max_health;
	// else - не нужно 
	return current_health;
}

// Задание: Создай функцию расчета урона с шансом крита.
int calculate_damage(int base_damage, int crital_chance) {
	int randValue = rand() % 100;

	if (randValue < crital_chance) {
		return base_damage * 2;
	}

	return base_damage;
}

// Задание: Создай функцию, проверяющую достаточно ли маны для заклинания.
bool can_cast_spell(int current_mana, int spell_cost) {
	if (current_mana >= spell_cost) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int health = 30;
	int max_health = 100;

	// Вызываем фукнцию heal и пристовить ее результат 
	health = heal(health, 40);

	cout << "Текущее здоровье: " << health << endl;

	// Увеличиваем жизнь в цикле до максимального значения
	while (health < max_health) {
		health = heal(health, 40);

		if (health == max_health)
			break;
	}

	cout << "Здоровье после полного лечения: " << health << endl;

	int damage = calculate_damage(25, 25);
	cout << "Нанесенный урон: " << damage << endl;

	int current_mana = 20;
	int fireball_cost = 25;

	if (can_cast_spell(current_mana, fireball_cost)) {
		cout << "Можем применить заклинание!" << endl;
		current_mana -= fireball_cost; // current_mana = current_mana - fireball_cost;
	}
	else {
		cout << "Недостаточно маны!" << endl;
	}

	cout << "Осталось маны: " << current_mana << endl;
}


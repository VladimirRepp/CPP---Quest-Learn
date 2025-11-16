#include <iostream>
#include <Windows.h>
using namespace std;

// Задание : Создай функцию расчета урона с шансом крита.

// Задание : Создай функцию, проверяющую достаточно ли маны для заклинания.



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

}

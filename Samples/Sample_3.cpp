#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Задание 1: Выведи обратный отсчет от 5 до 1 с сообщением 
	// "Заклинание активировано!"
	int i = 5;
	 
	// Пример 1: for - цикл
	for (; i > 0; i--) // i-- <-> i = i - 1
	{
		cout << i << "..." << endl;
	}
	cout << "Заклинание 1 активировано!" << endl;

	// Пример 2: while - цикл 
	i = 5;
	
	while (i > 0) {
		cout << i-- << "..." << endl;
	}
	cout << "Заклинание 2 активировано!" << endl;

	// Пример 3: do while - цикл 
	i = 5;
	do {
		cout << i-- << "..." << endl;
	} while (i > 0);
	cout << "Заклинание 3 активировано!" << endl;

	// Задание 2: Обойди 7 комнат и в каждой проверь, есть ли сокровище.
	srand(time(0));
	int golds_found = 0;

	cout << "time(0) = " << time(0) << endl;
	cout << "rand() = " << rand() % 10 << endl; // вывод случайного число от 0 до 9 (10 не включается в этот диапазон)

	for (int room = 1; room <= 7; room++) {
		bool has_gold = rand() % 2; 

		if (has_gold == true) {
			cout << "В комнате " << room << " - найдено золото!" << endl;
			golds_found += 1;
		}
		else {
			cout << "В комнате " << room << " - пусто!" << endl;
		}
	}

	cout << "Собранно сокровищ = " << golds_found << endl;

	// Задание 3: Реализуй движение по коридору пока герой не найдет выход.
	int steps = 0;

	while (true) {
		steps++;
		cout << "Шаг " << steps << ": продолжаем идти..." << endl;

		// Условие выхода из бесконечного коридора 
		if (rand() % 10 == 0) {
			cout << "Шаг " << steps << ": найден выход!" << endl;
			break;
		}
	}

	cout << "Потербовалось " << steps << " шагов для выхода!" << endl;
}

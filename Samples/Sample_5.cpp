#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

// Задание: Создай инвентарь на 5 ячеек и добавь в него предметы.
void BaseInventory_StaticArray() {
	// Реализуем статичный массив 
	// Тогда, когда зарнее знаем (до запуска программы) размер массива 
	// То есть память под него выделяется  
	// перед запуском программы 
	string inventory[5];

	inventory[0] = "Меч";
	inventory[1] = "Щит";
	inventory[2] = "Закленание - Фаир бол";
	inventory[3] = "Закленание - Здоровье";
	inventory[4] = "Закленание - молния";

	cout << "Мой инвентарь:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "[" << i << "] элемент: " << inventory[i] << endl;
	}
}

void BaseInventory_DynamicArray() {
	// Реализуем динамический массив 
	// Тогда, когда заранее не знаем (до запуска) размер массива 
	// То есть память под него выделяется 
	// во время работы программы 

	int countInventory = 0;

	cout << "Укажите размер инвентаря: ";
	cin >> countInventory;

	string* inventory = new string[countInventory]; // выделение памяти

	for (int i = 0; i < countInventory; i++) {
		cout << "Введите [" << i << "] элемент: ";
		cin >> inventory[i];
	}

	cout << "Мой инвентарь:" << endl;
	for (int i = 0; i < countInventory; i++) {
		cout << "[" << i << "] элемент: " << inventory[i] << endl;
	}

	delete[] inventory; // освободить память
}

void BaseInventory_Vector() {
	// Реализуем через вектор 
	// Тогда, когда заранее не знаем (до запуска) размер массива 
	// То есть примерно как динамический массив 
	// только работа с памятью происходит автоматически 

	int countInventory = 0;

	cout << "Укажите размер инвентаря: ";
	cin >> countInventory;

	vector<string> inventory(countInventory); // память выделаяется автоматически 

	for (int i = 0; i < countInventory; i++) {
		cout << "Введите [" << i << "] элемент: ";
		cin >> inventory[i];
	}

	cout << "Мой инвентарь:" << endl;
	for (int i = 0; i < countInventory; i++) {
		cout << "[" << i << "] элемент: " << inventory[i] << endl;
	}

	// Память освобождается автоматически
}

// Задание: Реализуй добавление и удаление предметов из инвентаря.

// Задание: Реализуй поиск конкретного предмета в инвентаре.

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//BaseInventory_StaticArray();
	//BaseInventory_DynamicArray();
	BaseInventory_Vector();
}

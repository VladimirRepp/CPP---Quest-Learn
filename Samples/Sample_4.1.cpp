#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

// В этом примере работаем с глобальными переменными 
// то есть они доступны везде в функциях под ними
int character_level = 0;
int character_hp = 0;
int character_mana = 0;
int character_damage = 0;

// Домашнее задание 5: 
// Создай библиотеку магических функций : create_character() 
// (создает персонажа со случайными характеристиками), 
// level_up() (увеличивает характеристики), restore_stats() 
// (восстанавливает здоровье и ману).Продемонстрируй их работу в main.

// возвращаемый_тип_данных название_функции (аргументы)
// { - начало тела функции 
// ... что то в функции 
// } - конец тела функции 

// создает персонажа со случайными характеристиками
void create_character() 
{
    character_level = rand() % 10;
    character_hp = rand() % 100;
    character_mana = rand() % 100;
    character_damage = rand() % 100;
}

// увеличивает характеристики
void level_up() {
    character_level += rand() % 10;

    character_hp += rand() % 10;
    character_mana += rand() % 10;
    character_damage += rand() % 10;
}

// восстанавливает здоровье и ману
void restore_stats(int character_base_hp, int character_base_mana) {
    character_hp = character_base_hp;
    character_mana = character_base_mana;
}


void print(string header) {
    cout << header << endl;
    cout << "Уровень: " << character_level << endl;
    cout << "Жизни: " << character_hp << endl;
    cout << "Мана: " << character_mana << endl;
    cout << "Урон: " << character_damage << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    // Локальная переменная 
    string character_name;

    cout << "Введите имя героя: ";
    cin >> character_name;

    // В функцию можно передать значение по ссылки 
    // Или работать с глобальными переменными
    create_character();
    print("=== Базовые характиристики героя ===");

    int character_base_hp = character_hp;
    int character_base_mana = character_mana;    

    level_up();
    print("=== Характиристики героя после level_up ===");

    restore_stats(character_base_hp, character_base_mana);
    print("=== Характиристики героя после restore_stats ===");
}
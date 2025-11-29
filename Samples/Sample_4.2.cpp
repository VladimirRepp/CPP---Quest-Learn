#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

// В этом примере оспользуемся ссылками

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
void create_character(int& character_level, int& character_hp,
    int& character_mana, int& character_damage)
{
    // Если в функцию аргумент приходит не как ссылка 
    // то в функции создается копия этого аргумента 
    // то есть, берется значение которое мы отправили 
    // и записывается в копию. 
    // Но когда выходим из функции, копия удаляется.
    // & - аргумент передается как ссылка

    character_level = rand() % 10;
    character_hp = rand() % 100;
    character_mana = rand() % 100;
    character_damage = rand() % 100;
}

// увеличивает характеристики
void level_up(int& character_level, int& character_hp,
    int& character_mana, int& character_damage) {
    character_level += rand() % 10;

    character_hp += rand() % 10;
    character_mana += rand() % 10;
    character_damage += rand() % 10;
}

// восстанавливает здоровье и ману
void restore_stats(int character_base_hp, int character_base_mana,
    int& character_hp, int& character_mana) {
    character_hp = character_base_hp;
    character_mana = character_base_mana;
}

void print(string header, 
    int character_level, int character_hp,
    int character_mana, int character_damage) {
    
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

    // Локальные переменные 
    int character_level = 0;
    int character_hp = 0;
    int character_mana = 0;
    int character_damage = 0;
    
    create_character(character_level, character_hp, character_mana, character_damage);
    print("=== Базовые характеристики ===",
        character_level, character_hp, character_mana, character_damage);

    int character_base_hp = character_hp;
    int character_base_mana = character_mana;

    level_up(character_level, character_hp, character_mana, character_damage);
    print("=== Характиристики героя после level_up ===", 
        character_level, character_hp, character_mana, character_damage);

    restore_stats(character_base_hp, character_base_mana,
        character_hp, character_mana);
    print("=== Характиристики героя после restore_stats ===",
        character_level, character_hp, character_mana, character_damage);
}
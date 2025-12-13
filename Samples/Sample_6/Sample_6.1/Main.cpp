#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>  // Добавлен для time()

#include "Player.h"
#include "Enemy.h"

using namespace std;

// Пример функции
void Heal(int& current_health, int amount_health) {
    current_health += amount_health;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned int>(time(0)));

    string name;
    int health = rand() % 100;
    int damage = rand() % 100;
    int level = rand() % 10;

    cout << "Введите имя игрока: ";
    cin >> name;

    Player player(name, health, damage, level);
    Enemy ogr("ogr", rand() % 100, rand() % 100, rand() % 10);

    player.PrintStats();
    ogr.Attack(player);

    if (player.IsAlive()) {
        cout << "Игрок жив!" << endl;
    }
    else {
        cout << "Нужно срочное лечение!" << endl;
        player.Heal(rand() % 100);
    }

    player.Attack(ogr);

    cout << "Характеристики игрока" << endl;
    player.PrintStats();

    cout << "Характеристики огра" << endl;
    ogr.PrintStats();

    return 0;
}
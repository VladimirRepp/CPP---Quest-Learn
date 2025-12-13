// ============================================================================
// ФАЙЛ: monsters.cpp - РЕАЛИЗАЦИЯ МОНСТРОВ
// ============================================================================
// КАЖДЫЙ КЛАСС ИМЕЕТ УНИКАЛЬНУЮ РЕАЛИЗАЦИЮ
// Но все они совместимы через базовый класс Character
// ============================================================================

#include "monsters.h"
#include <iostream>

// ============================================================================
// РЕАЛИЗАЦИЯ КЛАССА ОГР
// ============================================================================
Ogre::Ogre(const std::string& name, int level)
    : Character(name, level) {
    // Огр сильнее базового персонажа
    maxHealth += 100;
    health = maxHealth;
}

void Ogre::attack(Character* target) {
    if (!isAlive) return;
    
    // Огр наносит случайный урон (сильный но непредсказуемый)
    int damage = (level * 3) + (rand() % 20);
    
    std::cout << " <- " << name << " бьет дубиной " << target->getName() << "!\n";
    std::cout << "   Наносит " << damage << " урона!\n";
    
    target->takeDamage(damage);
}

void Ogre::specialAbility() {
    std::cout << " <- " << name << " использует 'Землетрясение'!\n";
    std::cout << "   Все вокруг получают урон!\n";
}

void Ogre::roar() {
    std::cout << " <- " << name << " издает оглушительный рев!\n";
}

// ============================================================================
// РЕАЛИЗАЦИЯ КЛАССА ДРАКОН
// ============================================================================
Dragon::Dragon(const std::string& name, int level)
    : Character(name, level), canBreatheFire(true) {
    // Дракон - очень сильный
    maxHealth = 200 + (level * 50);
    health = maxHealth;
}

void Dragon::attack(Character* target) {
    if (!isAlive) return;
    
    int damage = level * 10;  // Очень сильная атака
    
    std::cout << " <- " << name << " атакует когтями " << target->getName() << "!\n";
    std::cout << "   Наносит " << damage << " сокрушительного урона!\n";
    
    target->takeDamage(damage);
}

void Dragon::takeDamage(int damage) {
    if (!isAlive) return;
    
    // Дракон получает меньше урона
    int actualDamage = damage / 2;
    if (actualDamage < 1) actualDamage = 1;
    
    std::cout << " <- Чешуя дракона поглощает часть урона!\n";
    
    Character::takeDamage(actualDamage);
}

void Dragon::specialAbility() {
    std::cout << " <- " << name << " использует 'Огненное дыхание'!\n";
    canBreatheFire = false;  // Нельзя использовать сразу снова
    std::cout << "   Дракон не может дышать огнем следующий ход\n";
}

void Dragon::breatheFire(Character* target) {
    if (canBreatheFire) {
        std::cout << " <- " << name << " дышит огнем на " 
                  << target->getName() << "!\n";
        target->takeDamage(level * 15);
        canBreatheFire = false;
    } else {
        std::cout << "Дракон еще не восстановил свое огненное дыхание!\n";
    }
}

void Dragon::fly() {
    std::cout << " <- " << name << " взлетает в небо!\n";
}

// ============================================================================
// РЕАЛИЗАЦИЯ КЛАССА ПРИЗРАК
// ============================================================================
Ghost::Ghost(const std::string& name, int level)
    : Character(name, level), isVisible(true) {
    // Призрак имеет мало здоровья, но неуязвим
    maxHealth = 30 + (level * 5);
    health = maxHealth;
}

void Ghost::attack(Character* target) {
    if (!isAlive) return;
    
    int damage = level * 3;
    
    if (!isVisible) {
        std::cout << " <- Невидимый " << name << " атакует " 
                  << target->getName() << " из тени!\n";
        damage *= 2;  // Критический урон из невидимости
    } else {
        std::cout << " <- " << name << " пугает " << target->getName() << "!\n";
    }
    
    std::cout << "   Наносит " << damage << " урона!\n";
    target->takeDamage(damage);
}

void Ghost::takeDamage(int damage) {
    if (!isAlive) return;
    
    if (!isVisible) {
        // Невидимого призрака невозможно атаковать
        std::cout << " <- " << name << " невидим! Атака прошла насквозь!\n";
        return;
    }
    
    // Видимый призрак получает урон
    Character::takeDamage(damage);
}

void Ghost::specialAbility() {
    std::cout << " <- " << name << " использует 'Фазовый сдвиг'!\n";
    becomeInvisible();
}

void Ghost::becomeInvisible() {
    isVisible = false;
    std::cout << " <- " << name << " становится невидимым!\n";
}

void Ghost::becomeVisible() {
    isVisible = true;
    std::cout << " <- " << name << " становится видимым!\n";
}
// ============================================================================
// КОНЕЦ РЕАЛИЗАЦИИ МОНСТРОВ
// ============================================================================
#include "monsters.h"
#include <iostream>

// Реализация класса Огр
Ogre::Ogre(const std::string& name, int level)
    : Character(name, level, 150 + level * 20) {}

void Ogre::attack(std::shared_ptr<Character> target) {
    if (!isAlive) return;
    
    int damage = level * 6;
    std::cout << "👹 " << name << " бьет дубиной " << target->getName()
              << " и наносит " << damage << " урона\n";
    target->takeDamage(damage);
}

void Ogre::specialAbility() {
    std::cout << "👹 " << name << " использует 'Землетрясение'!\n";
}

// Реализация класса Дракон
Dragon::Dragon(const std::string& name, int level)
    : Character(name, level, 200 + level * 30), firePower(level * 10) {}

void Dragon::attack(std::shared_ptr<Character> target) {
    if (!isAlive) return;
    
    int damage = level * 8;
    std::cout << "🐉 " << name << " атакует когтями " << target->getName()
              << " и наносит " << damage << " урона\n";
    target->takeDamage(damage);
}

void Dragon::specialAbility() {
    std::cout << "🐉 " << name << " использует 'Огненное дыхание'!\n";
}

void Dragon::breatheFire(std::shared_ptr<Character> target) {
    std::cout << "🐉 " << name << " дышит огнем на " 
              << target->getName() << "!\n";
    target->takeDamage(firePower);
}

// Реализация класса Призрак
Ghost::Ghost(const std::string& name, int level)
    : Character(name, level, 40 + level * 5) {}

void Ghost::attack(std::shared_ptr<Character> target) {
    if (!isAlive) return;
    
    int damage = level * 3;
    std::cout << "👻 " << name << " пугает " << target->getName()
              << " и наносит " << damage << " урона\n";
    target->takeDamage(damage);
}

// Призрак получает меньше урона - уникальное поведение
void Ghost::takeDamage(int damage) {
    int reducedDamage = damage / 2; // Призрак получает половину урона
    std::cout << "👻 Призрак " << name << " неуязвим! Получает только "
              << reducedDamage << " урона вместо " << damage << "\n";
    Character::takeDamage(reducedDamage);
}

void Ghost::specialAbility() {
    std::cout << "👻 " << name << " становится невидимым!\n";
}
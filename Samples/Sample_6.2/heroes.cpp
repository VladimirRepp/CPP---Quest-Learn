#include "heroes.h"
#include <iostream>

// Реализация класса Лучник
Archer::Archer(const std::string& name, int level)
    : Character(name, level, 80 + level * 10) {}

void Archer::attack(std::shared_ptr<Character> target) {
    if (!isAlive) {
        std::cout << name << " мертв и не может атаковать!\n";
        return;
    }
    
    // Улучшенная атака для лучника
    int damage = level * 3;
    std::cout << "🏹 " << name << " стреляет в " << target->getName()
              << " и наносит " << damage << " урона\n";
    target->takeDamage(damage);
}

void Archer::specialAbility() {
    std::cout << "🏹 " << name << " использует 'Метеоритный дождь'!\n";
}

// Реализация класса Воин
Warrior::Warrior(const std::string& name, int level)
    : Character(name, level, 120 + level * 15) {}

void Warrior::attack(std::shared_ptr<Character> target) {
    if (!isAlive) {
        std::cout << name << " мертв и не может атаковать!\n";
        return;
    }
    
    int damage = level * 4;
    std::cout << "⚔️ " << name << " атакует мечом " << target->getName()
              << " и наносит " << damage << " урона\n";
    target->takeDamage(damage);
}

void Warrior::specialAbility() {
    std::cout << "⚔️ " << name << " использует 'Вихрь клинков'!\n";
}

// Реализация класса Маг
Mage::Mage(const std::string& name, int level)
    : Character(name, level, 60 + level * 5), mana(50 + level * 10) {}

void Mage::attack(std::shared_ptr<Character> target) {
    if (!isAlive) {
        std::cout << name << " мертв и не может атаковать!\n";
        return;
    }
    
    if (mana >= 10) {
        mana -= 10;
        int damage = level * 5;
        std::cout << "🔮 " << name << " бросает огненный шар в " 
                  << target->getName() << " и наносит " << damage << " урона\n";
        target->takeDamage(damage);
    } else {
        std::cout << "У " << name << " недостаточно маны!\n";
        Character::attack(target); // Вызов метода базового класса
    }
}

void Mage::specialAbility() {
    std::cout << "🔮 " << name << " использует 'Ледяную тюрьму'!\n";
    mana -= 30;
}

void Mage::castSpell(std::shared_ptr<Character> target) {
    std::cout << "🔮 " << name << " накладывает проклятие на " 
              << target->getName() << "!\n";
    target->takeDamage(15);
}
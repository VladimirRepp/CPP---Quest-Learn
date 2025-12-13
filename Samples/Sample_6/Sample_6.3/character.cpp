#include "character.h"
#include <iostream>

// Конструктор базового класса
// ИНКАПСУЛЯЦИЯ: инициализация всех полей в одном месте
Character::Character(const std::string& name, int level, int health)
    : name(name), level(level), maxHealth(health), health(health), isAlive(true) {
    std::cout << "Создан " << getType() << ": " << name 
              << " (уровень " << level << ")\n";
}

// Лечение персонажа
void Character::heal(int amount) {
    if (!isAlive) {
        std::cout << name << " мертв и не может лечиться!\n";
        return;
    }
    
    health += amount;
    if (health > maxHealth) {
        health = maxHealth;
    }
    std::cout << name << " вылечен на " << amount 
              << " HP. Теперь у него " << health << " HP\n";
}

// Получение урона
void Character::takeDamage(int damage) {
    if (!isAlive) {
        std::cout << name << " уже мертв!\n";
        return;
    }
    
    health -= damage;
    std::cout << name << " получает " << damage << " урона. ";
    
    if (health <= 0) {
        health = 0;
        isAlive = false;
        std::cout << name << " погиб!\n";
    } else {
        std::cout << "Осталось " << health << " HP\n";
    }
}

// Базовая атака - может быть переопределена
void Character::attack(std::shared_ptr<Character> target) {
    if (!isAlive) {
        std::cout << name << " мертв и не может атаковать!\n";
        return;
    }
    
    if (!target->getIsAlive()) {
        std::cout << name << " не может атаковать мертвого " 
                  << target->getName() << "!\n";
        return;
    }
    
    int damage = level * 2; // Базовая формула урона
    std::cout << name << " атакует " << target->getName() 
              << " и наносит " << damage << " урона\n";
    target->takeDamage(damage);
}
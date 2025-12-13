// ============================================================================
// ФАЙЛ: heroes.cpp - РЕАЛИЗАЦИЯ ГЕРОЕВ
// ============================================================================
// ДЕМОНСТРАЦИЯ ПРИНЦИПА НАСЛЕДОВАНИЯ:
// 1. Переиспользование кода из базового класса
// 2. Расширение функциональности
// 3. Изменение поведения через переопределение
// ============================================================================

#include "heroes.h"
#include <iostream>

// ============================================================================
// РЕАЛИЗАЦИЯ КЛАССА ЛУЧНИК
// ============================================================================
Archer::Archer(const std::string& name, int level)
    : Character(name, level), arrows(10 + level * 2) {
    // Вызов конструктора родительского класса
    // Инициализация специфичных полей
}

void Archer::attack(Character* target) {
    if (!isAlive) return;
    
    if (arrows <= 0) {
        std::cout << "У " << name << " закончились стрелы!\n";
        Character::attack(target);  // Вызов метода родителя
        return;
    }
    
    arrows--;
    int damage = level * 4;  // Лучник наносит больше урона
    
    std::cout << " -> " << name << " стреляет в " << target->getName()
              << " (осталось стрел: " << arrows << ")\n";
    std::cout << "   Наносит " << damage << " урона!\n";
    
    target->takeDamage(damage);
}

void Archer::specialAbility() {
    std::cout << " -> " << name << " использует 'Метеоритный дождь'!\n";
    // Особый эффект...
}

void Archer::shootArrow(Character* target) {
    // Альтернативный метод атаки
    std::cout << " -> " << name << " делает прицельный выстрел!\n";
    attack(target);
}

// ============================================================================
// РЕАЛИЗАЦИЯ КЛАССА ВОИН
// ============================================================================
Warrior::Warrior(const std::string& name, int level)
    : Character(name, level), armor(level * 5) {
    // Воин начинает с дополнительным здоровьем
    maxHealth += 50;
    health = maxHealth;
}

void Warrior::takeDamage(int damage) {
    if (!isAlive) return;
    
    // Воин получает меньше урона благодаря броне
    int actualDamage = damage - (armor / 10);
    if (actualDamage < 1) actualDamage = 1;  // Минимум 1 урон
    
    std::cout << " -> " << name << " блокирует часть урона броней (" 
              << armor << ")\n";
    
    Character::takeDamage(actualDamage);
}

void Warrior::attack(Character* target) {
    if (!isAlive) return;
    
    int damage = level * 5;  // Воин наносит много урона
    
    std::cout << " -> " << name << " мощно атакует " << target->getName()
              << " мечом!\n";
    std::cout << "   Наносит " << damage << " урона!\n";
    
    target->takeDamage(damage);
}

void Warrior::specialAbility() {
    std::cout << " -> " << name << " использует 'Вихрь клинков'!\n";
    armor += 10;  // Увеличиваем броню
    std::cout << "   Броня увеличена до " << armor << "!\n";
}

void Warrior::block() {
    std::cout << " -> " << name << " принимает защитную стойку!\n";
    // Уменьшает следующий полученный урон
}

// ============================================================================
// РЕАЛИЗАЦИЯ КЛАССА МАГ
// ============================================================================
Mage::Mage(const std::string& name, int level)
    : Character(name, level), mana(0) {
    calculateMaxMana();
    mana = maxMana;
    
    // Маг начинает с меньшим здоровьем
    maxHealth -= 20;
    if (maxHealth < 10) maxHealth = 10;
    health = maxHealth;
}

void Mage::calculateMaxMana() {
    maxMana = 30 + (level * 15);
}

void Mage::attack(Character* target) {
    if (!isAlive) return;
    
    if (mana >= 15) {
        mana -= 15;
        int damage = level * 6;  // Маг наносит большой урона
        
        std::cout << " -> " << name << " бросает огненный шар в " 
                  << target->getName() << "!\n";
        std::cout << "   Тратит 15 маны (осталось: " << mana << ")\n";
        std::cout << "   Наносит " << damage << " магического урона!\n";
        
        target->takeDamage(damage);
    } else {
        std::cout << "У " << name << " недостаточно маны для заклинания!\n";
        Character::attack(target);  // Базовая атака
    }
}

void Mage::takeDamage(int damage) {
    if (!isAlive) return;
    
    // Маг получает больше урона
    int actualDamage = damage * 2;
    
    std::cout << " -> " << name << " уязвим и получает двойной урон!\n";
    
    Character::takeDamage(actualDamage);
}

void Mage::specialAbility() {
    if (mana >= 50) {
        mana -= 50;
        std::cout << " -> " << name << " использует 'Ледяную тюрьму'!\n";
        std::cout << "   Все враги заморожены на 1 ход!\n";
    } else {
        std::cout << "Недостаточно маны для суперспособности!\n";
    }
}

void Mage::castSpell(Character* target) {
    std::cout << " -> " << name << " накладывает проклятие на " 
              << target->getName() << "!\n";
    target->takeDamage(level * 2);
}

void Mage::restoreMana(int amount) {
    mana += amount;
    if (mana > maxMana) mana = maxMana;
    std::cout << " -> " << name << " восстановил " << amount 
              << " маны. Теперь: " << mana << "/" << maxMana << " маны\n";
}
// ============================================================================
// КОНЕЦ РЕАЛИЗАЦИИ ГЕРОЕВ
// ============================================================================
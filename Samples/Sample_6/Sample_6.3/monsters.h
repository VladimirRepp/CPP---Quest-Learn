#pragma once
#include "character.h"
#include <memory>

// ======================================================
// ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА:
// Монстры тоже наследуются от Character, но ведут себя по-другому
// Один интерфейс - множество реализаций
// ======================================================

class Ogre : public Character {
public:
    Ogre(const std::string& name, int level);
    
    void attack(std::shared_ptr<Character> target) override;
    void specialAbility() override;
    std::string getType() const override { return "Огр"; }
};

class Dragon : public Character {
private:
    int firePower; // Инкапсуляция специфичного для дракона поля
public:
    Dragon(const std::string& name, int level);
    
    void attack(std::shared_ptr<Character> target) override;
    void specialAbility() override;
    std::string getType() const override { return "Дракон"; }
    
    void breatheFire(std::shared_ptr<Character> target);
};

class Ghost : public Character {
public:
    Ghost(const std::string& name, int level);
    
    // ПОЛИМОРФИЗМ: уникальное поведение для призрака
    void attack(std::shared_ptr<Character> target) override;
    void takeDamage(int damage) override; // Переопределяем получение урона
    void specialAbility() override;
    std::string getType() const override { return "Призрак"; }
};
#pragma once
#include "character.h"
#include <memory>

// ======================================================
// ДЕМОНСТРАЦИЯ НАСЛЕДОВАНИЯ:
// Классы героев наследуются от Character
// Отношение "является" (Лучник является Персонажем)
// ======================================================

class Archer : public Character {
public:
    Archer(const std::string& name, int level);
    
    // ПОЛИМОРФИЗМ: переопределение виртуальных методов
    void attack(std::shared_ptr<Character> target) override;
    void specialAbility() override;
    std::string getType() const override { return "Лучник"; }
};

class Warrior : public Character {
public:
    Warrior(const std::string& name, int level);
    
    void attack(std::shared_ptr<Character> target) override;
    void specialAbility() override;
    std::string getType() const override { return "Воин"; }
};

class Mage : public Character {
private:
    int mana; // ДОПОЛНИТЕЛЬНАЯ ИНКАПСУЛЯЦИЯ: новое приватное поле
public:
    Mage(const std::string& name, int level);
    
    void attack(std::shared_ptr<Character> target) override;
    void specialAbility() override;
    std::string getType() const override { return "Маг"; }
    
    // Специфический метод только для Мага
    void castSpell(std::shared_ptr<Character> target);
};
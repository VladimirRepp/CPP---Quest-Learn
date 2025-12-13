// ============================================================================
// ФАЙЛ: monsters.h - КЛАССЫ МОНСТРОВ
// ============================================================================
// ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА:
// Один интерфейс (Character) - множество реализаций
// 
// Герои и монстры - разные классы, но оба наследуют Character
// Можно обрабатывать их одинаково через указатель на Character
// ============================================================================

#pragma once
#include "character.h"

// ============================================================================
// КЛАСС ОГР - ГЛУПЫЙ И СИЛЬНЫЙ МОНСТР
// ============================================================================
class Ogre : public Character {
public:
    Ogre(const std::string& name, int level);
    
    // Переопределение методов
    void attack(Character* target) override;
    void specialAbility() override;
    std::string getType() const override { return "Огр"; }
    
    // Специфичное поведение
    void roar();  // Огр может реветь
};

// ============================================================================
// КЛАСС ДРАКОН - МОЩНЫЙ БОСС
// ============================================================================
class Dragon : public Character {
private:
    bool canBreatheFire;  // Может ли дышать огнем
    
public:
    Dragon(const std::string& name, int level);
    
    // Полное переопределение поведения
    void attack(Character* target) override;
    void takeDamage(int damage) override;
    void specialAbility() override;
    std::string getType() const override { return "Дракон"; }
    
    // Уникальные способности дракона
    void breatheFire(Character* target);
    void fly();  // Дракон может летать
};

// ============================================================================
// КЛАСС ПРИЗРАК - НЕУЯЗВИМЫЙ МОНСТР
// ============================================================================
class Ghost : public Character {
private:
    bool isVisible;  // Видим ли призрак
    
public:
    Ghost(const std::string& name, int level);
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ СЛОЖНОГО ПЕРЕОПРЕДЕЛЕНИЯ
    // ========================================================================
    void attack(Character* target) override;
    void takeDamage(int damage) override;  // Призрак неуязвим!
    void specialAbility() override;
    std::string getType() const override { return "Призрак"; }
    
    // Особое поведение призрака
    void becomeInvisible();
    void becomeVisible();
    bool getIsVisible() const { return isVisible; }
};
// ============================================================================
// КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССОВ МОНСТРОВ
// ============================================================================
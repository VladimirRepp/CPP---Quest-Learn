#pragma once
#include <iostream>
#include <string>
#include <memory>

/**
 * ======================================================
 * ЛЕКЦИЯ: ПРИНЦИПЫ ООП В C++
 * ======================================================
 * 
 * 1. ИНКАПСУЛЯЦИЯ (Encapsulation):
 *    - Скрытие внутренней реализации от пользователя
 *    - Доступ к данным только через публичные методы
 *    - Защита целостности объекта
 *    
 * 2. НАСЛЕДОВАНИЕ (Inheritance):
 *    - Создание новых классов на основе существующих
 *    - Переиспользование кода
 *    - Иерархия "является" (is-a relationship)
 *    
 * 3. ПОЛИМОРФИЗМ (Polymorphism):
 *    - Возможность объектов разных классов отвечать
 *      на одни и те же сообщения
 *    - Виртуальные функции
 *    - Позднее связывание (dynamic binding)
 *    
 * 4. АБСТРАКЦИЯ (Abstraction):
 *    - Сокрытие сложности, выделение существенного
 *    - Интерфейсы и абстрактные классы
 * ======================================================
 */

// Интерфейс для всех атакующих существ
// ДЕМОНСТРАЦИЯ АБСТРАКЦИИ: скрываем детали реализации атаки
class IAttacker {
public:
    virtual void attack(std::shared_ptr<class Character> target) = 0;
    virtual ~IAttacker() = default;
};

// Базовый класс для всех персонажей
// ДЕМОНСТРАЦИЯ ИНКАПСУЛЯЦИИ: поля защищены, доступ через методы
class Character : public IAttacker {
protected:
    std::string name;
    int level;
    int health;
    int maxHealth;
    
    // ПРИНЦИП ИНКАПСУЛЯЦИИ: защищенное поле, нельзя изменить напрямую
    bool isAlive;
    
public:
    Character(const std::string& name, int level, int health);
    virtual ~Character() = default;
    
    // Геттеры - пример инкапсуляции
    std::string getName() const { return name; }
    int getLevel() const { return level; }
    int getHealth() const { return health; }
    bool getIsAlive() const { return isAlive; }
    
    // Базовые методы
    void heal(int amount);          // Лечение персонажа
    virtual void takeDamage(int damage);    // Получение урона
    
    // Виртуальные методы для переопределения
    virtual void attack(std::shared_ptr<Character> target) override;
    virtual void specialAbility() = 0; // Чисто виртуальная функция
    
    // ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА: виртуальная функция
    virtual std::string getType() const { return "Персонаж"; }
    
    // Статический метод - относится ко всем объектам класса
    static void gameRules() {
        std::cout << "=== ПРАВИЛА ИГРЫ ===\n";
        std::cout << "1. Персонажи атакуют друг друга\n";
        std::cout << "2. При здоровье <= 0 персонаж умирает\n";
        std::cout << "3. Лечение восстанавливает здоровье\n";
    }
};
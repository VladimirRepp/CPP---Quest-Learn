#include <iostream>
#include <memory>
#include <vector>
#include <Windows.h>
#include "character.h"
#include "heroes.h"
#include "monsters.h"

/**
 * ======================================================
 * ДЕМОНСТРАЦИЯ ВСЕХ ПРИНЦИПОВ ООП В ДЕЙСТВИИ:
 * 1. ИНКАПСУЛЯЦИЯ - работаем только через публичные методы
 * 2. НАСЛЕДОВАНИЕ - все персонажи наследуются от Character
 * 3. ПОЛИМОРФИЗМ - один метод attack() работает для всех типов
 * 4. АБСТРАКЦИЯ - не важно какой конкретно персонаж, главное что он умеет атаковать
 * Project Properties → C/C++ → Language → C++ Language Standard → С++ 20
 * ======================================================
 */

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "=== ДЕМОНСТРАЦИЯ ООП В ИГРЕ ===\n\n";
    
    // Демонстрация статического метода
    Character::gameRules();
    std::cout << "\n";
    
    // Создание героев с использованием умных указателей
    // ПОЛИМОРФИЗМ: указатель базового класса может указывать на объект производного
    std::shared_ptr<Character> legolas = std::make_shared<Archer>("Леголас", 5);
    std::shared_ptr<Character> conan = std::make_shared<Warrior>("Конан", 6);
    std::shared_ptr<Character> gandalf = std::make_shared<Mage>("Гэндальф", 8);
    
    std::cout << "\n";
    
    // Создание монстров
    std::shared_ptr<Character> shrek = std::make_shared<Ogre>("Шрек", 4);
    std::shared_ptr<Character> smaug = std::make_shared<Dragon>("Смауг", 10);
    std::shared_ptr<Character> casper = std::make_shared<Ghost>("Каспер", 3);
    
    std::cout << "\n=== НАЧАЛО БИТВЫ ===\n\n";
    
    // 1. Герои атакуют монстров
    std::cout << "----- ГЕРОИ АТАКУЮТ -----\n";
    legolas->attack(shrek);
    conan->attack(smaug);
    
    // Приведение типа для вызова специфичных методов
    std::dynamic_pointer_cast<Mage>(gandalf)->castSpell(casper);
    
    std::cout << "\n----- МОНСТРЫ КОНТРАТАКУЮТ -----\n";
    // 2. Монстры атакуют героев
    shrek->attack(conan);
    smaug->attack(gandalf);
    
    // Вызов специфичного метода Дракона
    std::dynamic_pointer_cast<Dragon>(smaug)->breatheFire(legolas);
    
    std::cout << "\n----- ЛЕЧЕНИЕ -----\n";
    // 3. Лечение
    conan->heal(30);
    gandalf->heal(20);
    
    std::cout << "\n----- СПЕЦИАЛЬНЫЕ СПОСОБНОСТИ -----\n";
    // 4. Использование специальных способностей
    // ПОЛИМОРФИЗМ: один метод specialAbility() работает для всех
    std::vector<std::shared_ptr<Character>> allCharacters = {
        legolas, conan, gandalf, shrek, smaug, casper
    };
    
    for (auto& character : allCharacters) {
        character->specialAbility();
    }
    
    std::cout << "\n----- МАССОВАЯ АТАКА -----\n";
    // 5. Массовая атака - демонстрация полиморфизма
    // АБСТРАКЦИЯ: не важно кто атакует кого, главное что все могут атаковать
    for (auto& attacker : allCharacters) {
        for (auto& target : allCharacters) {
            if (attacker != target && attacker->getIsAlive() && target->getIsAlive()) {
                attacker->attack(target);
                std::cout << "\n";
                break; // Чтобы не слишком затягивать
            }
        }
    }
    
    std::cout << "\n=== ИТОГИ БИТВЫ ===\n";
    // 6. Проверка состояния всех персонажей
    for (auto& character : allCharacters) {
        std::cout << character->getType() << " " << character->getName()
                  << ": " << (character->getIsAlive() ? "ЖИВ" : "МЕРТВ")
                  << ", HP: " << character->getHealth() << "\n";
    }
    
    std::cout << "\n=== ДЕМОНСТРАЦИЯ УНИКАЛЬНОСТИ ПРИЗРАКА ===\n";
    // 7. Демонстрация переопределенного метода takeDamage у Призрака
    casper->takeDamage(50); // Должен получить только 25 урона
    
    std::cout << "\n=== СОЗДАНИЕ КОПИЙ И ПРИВЕДЕНИЕ ТИПОВ ===\n";
    // Демонстрация RTTI (Runtime Type Information)
    for (auto& character : allCharacters) {
        if (auto dragon = std::dynamic_pointer_cast<Dragon>(character)) {
            std::cout << "Обнаружен дракон: " << dragon->getName() << "\n";
        } else if (auto mage = std::dynamic_pointer_cast<Mage>(character)) {
            std::cout << "Обнаружен маг: " << mage->getName() << "\n";
        }
    }
    
    std::cout << "\n=== КОНЕЦ ДЕМОНСТРАЦИИ ===\n";
    
    return 0;
}
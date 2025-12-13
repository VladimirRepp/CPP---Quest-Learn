// ============================================================================
// ФАЙЛ: main.cpp - ГЛАВНАЯ ПРОГРАММА
// ============================================================================
// ДЕМОНСТРАЦИЯ ВСЕХ ПРИНЦИПОВ ООП В ДЕЙСТВИИ:
// 1. ИНКАПСУЛЯЦИЯ - работа через интерфейсы
// 2. НАСЛЕДОВАНИЕ - иерархия классов
// 3. ПОЛИМОРФИЗМ - обработка разных типов через один интерфейс
// 4. АБСТРАКЦИЯ - скрытие сложности реализации
// ============================================================================

#include <iostream>
#include <vector>
#include <memory>  // Для умных указателей
#include "character.h"
#include "heroes.h"
#include "monsters.h"

// Функция для настройки консоли (для Windows)
#ifdef _WIN32
#include <windows.h>
void setupConsole() {
    SetConsoleOutputCP(65001);  // UTF-8
}
#endif

// ============================================================================
// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
// ============================================================================
void printSeparator() {
    std::cout << "\n" << std::string(50, '=') << "\n";
}

void printSection(const std::string& title) {
    std::cout << "\n>>> " << title << " <<<\n";
}

// ============================================================================
// ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА
// ============================================================================
// Эта функция принимает указатель на базовый класс,
// но работает с любым наследником!
void processCharacter(Character* character) {
    std::cout << "Обрабатываем: " << character->getName() 
              << " (" << character->getType() << ")\n";
}

// ============================================================================
// ДЕМОНСТРАЦИЯ РАБОТЫ С КОЛЛЕКЦИЕЙ РАЗНЫХ ТИПОВ
// ============================================================================
void demonstratePolymorphism() {
    printSection("ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА");
    
    // Создаем вектор указателей на базовый класс
    // Но храним в нем объекты разных типов!
    std::vector<Character*> characters;
    
    // Добавляем разных персонажей
    characters.push_back(new Archer("Леголас", 5));
    characters.push_back(new Warrior("Конан", 6));
    characters.push_back(new Mage("Гендальф", 8));
    characters.push_back(new Ogre("Шрек", 4));
    characters.push_back(new Dragon("Смауг", 10));
    characters.push_back(new Ghost("Каспер", 3));
    
    std::cout << "\nВсего создано персонажей: " 
              << Character::totalCharactersCreated << "\n";
    
    // Обрабатываем всех одинаково - это ПОЛИМОРФИЗМ!
    for (Character* character : characters) {
        processCharacter(character);
    }
    
    // Вызываем specialAbility для каждого - каждый делает по-своему!
    std::cout << "\nСпециальные способности:\n";
    for (Character* character : characters) {
        std::cout << "  ";
        character->specialAbility();
    }
    
    // Очищаем память
    for (Character* character : characters) {
        delete character;
    }
}

// ============================================================================
// ДЕМОНСТРАЦИЯ ИГРОВОЙ СИТУАЦИИ
// ============================================================================
void demonstrateGameplay() {
    printSection("ИГРОВАЯ СИТУАЦИЯ");
    
    // Создаем героев и монстров
    Archer* legolas = new Archer("Леголас", 5);
    Warrior* conan = new Warrior("Конан", 6);
    Mage* gandalf = new Mage("Гендальф", 8);
    
    Ogre* shrek = new Ogre("Шрек", 4);
    Dragon* smaug = new Dragon("Смауг", 10);
    Ghost* casper = new Ghost("Каспер", 3);
    
    // Сцена 1: Герои атакуют монстров
    printSection("ГЕРОИ АТАКУЮТ");
    legolas->attack(shrek);
    conan->attack(smaug);
    gandalf->attack(casper);
    
    printSeparator();
    
    // Сцена 2: Монстры контратакуют
    printSection("МОНСТРЫ КОНТРАТАКУЮТ");
    shrek->attack(legolas);
    smaug->attack(gandalf);
    casper->attack(conan);
    
    printSeparator();
    
    // Сцена 3: Лечение и восстановление
    printSection("ЛЕЧЕНИЕ И ВОССТАНОВЛЕНИЕ");
    legolas->heal(30);
    gandalf->restoreMana(20);
    conan->block();  // Специфичный метод Воина
    
    printSeparator();
    
    // Сцена 4: Специальные способности
    printSection("СПЕЦИАЛЬНЫЕ СПОСОБНОСТИ");
    legolas->specialAbility();
    shrek->roar();  // Специфичный метод Огра
    smaug->breatheFire(gandalf);
    casper->becomeInvisible();
    
    printSeparator();
    
    // Сцена 5: Приведение типов (RTTI)
    printSection("ПРИВЕДЕНИЕ ТИПОВ (RTTI)");
    
    // Проверка типа во время выполнения
    Character* mystery = smaug;
    
    if (auto* dragon = dynamic_cast<Dragon*>(mystery)) {
        std::cout << "mystery - это Дракон! Он может летать:\n";
        dragon->fly();
    }
    
    mystery = gandalf;
    if (auto* mage = dynamic_cast<Mage*>(mystery)) {
        std::cout << "mystery - это Маг! У него " 
                  << mage->getMana() << " маны\n";
    }
    
    // Освобождаем память
    delete legolas;
    delete conan;
    delete gandalf;
    delete shrek;
    delete smaug;
    delete casper;
}

// ============================================================================
// ДЕМОНСТРАЦИЯ ИНКАПСУЛЯЦИИ
// ============================================================================
void demonstrateEncapsulation() {
    printSection("ДЕМОНСТРАЦИЯ ИНКАПСУЛЯЦИИ");
    
    Warrior warrior("Арагорн", 7);
    
    // Попытка получить доступ к защищенным полям:
    // warrior.health = 1000;  // ОШИБКА: health is private!
    // warrior.level = 999;    // ОШИБКА: level is protected!
    
    // Правильный способ - через публичные методы:
    std::cout << "Имя: " << warrior.getName() << "\n";
    std::cout << "Уровень: " << warrior.getLevel() << "\n";
    std::cout << "Здоровье: " << warrior.getHealth() << "\n";
    std::cout << "Жив: " << (warrior.getIsAlive() ? "да" : "нет") << "\n";
    
    // Изменяем состояние через контролируемые методы:
    warrior.takeDamage(50);
    warrior.heal(30);
    
    // Защита от некорректных данных:
    std::cout << "\nПопытка некорректных действий:\n";
    warrior.heal(-10);      // Отрицательное лечение
    warrior.takeDamage(0);  // Нулевой урон
}

// ============================================================================
// ГЛАВНАЯ ФУНКЦИЯ
// ============================================================================
int main() {
#ifdef _WIN32
    setupConsole();
#endif
    
    std::cout << " ПРИМЕР ИГРЫ ДЛЯ ДЕМОНСТРАЦИИ ООП В C++ \n";
    
    // Выводим правила игры
    Character::printGameRules();
    
    printSeparator();
    
    // Демонстрируем инкапсуляцию
    demonstrateEncapsulation();
    
    printSeparator();
    
    // Демонстрируем полиморфизм
    demonstratePolymorphism();
    
    printSeparator();
    
    // Демонстрируем игровую ситуацию
    demonstrateGameplay();
    
    printSeparator();
    
    // Итоги
    std::cout << "\n=== ВЫВОДЫ И ПОДВЕДЕНИЕ ИТОГОВ ===\n\n";
    
    std::cout << "ПРИНЦИПЫ ООП, ПРОДЕМОНСТРИРОВАННЫЕ В ПРОГРАММЕ:\n\n";
    
    std::cout << "1. ИНКАПСУЛЯЦИЯ:\n";
    std::cout << "   - Поля name, health, level защищены\n";
    std::cout << "   - Доступ только через getName(), getHealth() и т.д.\n";
    std::cout << "   - takeDamage() проверяет корректность данных\n\n";
    
    std::cout << "2. НАСЛЕДОВАНИЕ:\n";
    std::cout << "   - Archer, Warrior, Mage наследуют Character\n";
    std::cout << "   - Ogre, Dragon, Ghost наследуют Character\n";
    std::cout << "   - Переиспользование кода из базового класса\n\n";
    
    std::cout << "3. ПОЛИМОРФИЗМ:\n";
    std::cout << "   - virtual методы attack(), takeDamage()\n";
    std::cout << "   - Один метод specialAbility() работает по-разному\n";
    std::cout << "   - Вектор Character* хранит разные типы объектов\n\n";
    
    std::cout << "4. АБСТРАКЦИЯ:\n";
    std::cout << "   - Класс Character - абстракция игрового персонажа\n";
    std::cout << "   - Не важно как именно атакует, важно что атакует\n";
    std::cout << "   - Интерфейс скрывает сложность реализации\n\n";
    
    std::cout << "ПРЕИМУЩЕСТВА ООП В ЭТОМ ПРИМЕРЕ:\n";
    std::cout << " Легко добавлять новых персонажей\n";
    std::cout << " Код легко читать и понимать\n";
    std::cout << " Можно изменять реализацию не меняя интерфейс\n";
    std::cout << " Исключается дублирование кода\n";
    
    std::cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===\n";
    
    return 0;
}
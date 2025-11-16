#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ------------------------ Характеристики героя ------------------------
	// Задание: 
	// Объяви переменные для характеристик героя: 
	// имя, уровень, здоровье, мана, сила атаки.
	string heroName = "Геральтл";
	int heroLevel = 1;
	float heroMaxHealth = 100.0f;
	float heroCurrentHealth = heroMaxHealth;
	int heroMaxMana = 50;
	int heroCurrentMana = heroMaxMana;
	float heroAttackPower = 15.5f;
	// Заклятья мага
	float fireballMultiplierDamage = 2.0f;
	float iceArrowMultiplierDamage = 1.5f;
	float lightningStrikeMultiplierDamage = 3.0f;
	float ghostStrikeMultiplierDamage = 2.5f;
	// Расход маны на заклятья
	int fireballManaCost = 10;
	int iceArrowManaCost = 8;
	int lightningStrikeManaCost = 20;
	int ghostStrikeManaCost = 15;

	cout << "Характеристики героя: " << endl;
	cout << "Имя героя: " << heroName << endl;
	cout << "Уровень героя: " << heroLevel << endl;
	cout << "Количество жизни героя: " << heroCurrentHealth << endl;
	cout << "Количество маны героя: " << heroCurrentMana << endl;
	cout << "Сила урон героя: " << heroAttackPower << endl << endl;

	system("pause");
	system("cls"); 

	// ------------------------ Калькулятор урона ------------------------
	// Задание: 
	// Рассчитай итоговый урон с учетом брони противника.
	float enemyBaseDamage = 45.0f;
	float enemyHealth = 10.0f;
	float enemyMultiplierDamage = 1.2f;
	string enemyType = "Огр"; // Огр или Скелет или Дракон или Призрак

	if (heroLevel < 10) {						// 1 ------ 10
		enemyMultiplierDamage = 1;
	}
	else if (heroLevel > 10 && heroLevel < 20) {// 10 ------ 20
		enemyMultiplierDamage = 2.1f;
	}
	else {										// 20 ------
		enemyMultiplierDamage = 3.5f; 
	}

	heroCurrentHealth = heroCurrentHealth - (enemyBaseDamage * enemyMultiplierDamage);

	// Задание: 
	// Проверь, готов ли герой к битве(здоровье > 50 и мана > 20).
	if (heroCurrentHealth < heroMaxHealth / 2 && heroCurrentMana < 20) {
		cout << "Внимание! Уровень здоровья ниже 50%! Отступаем!" << endl;
	}
	else {
		cout << "Бой продогжается!" << endl;

		// Задание: 
		// В зависимости от типа врага предложи эффективное
		float enemyCurrentHealth = enemyHealth;

		if (enemyType == "Огр") {
			cout << "Противник - Огр!" << endl;
			
			if (heroCurrentMana - fireballManaCost >= 0) {
				cout << "Используем огненный шар!" << endl;
				enemyCurrentHealth = enemyCurrentHealth - (heroAttackPower * fireballMultiplierDamage);
				heroCurrentMana -= fireballManaCost;
			}
			else {
				cout << "Недостаточно маны для огненного шара! Используем обычную атаку!" << endl;
				enemyCurrentHealth = enemyCurrentHealth - heroAttackPower;
			}
		}
		else if (enemyType == "Скелет") {
			cout << "Противник - Скелет!" << endl;
			
			if (heroCurrentMana - iceArrowManaCost >= 0) {
				cout << "Используем ледяные стрелы!" << endl;
				enemyCurrentHealth = enemyCurrentHealth - (heroAttackPower * iceArrowMultiplierDamage);
				heroCurrentMana -= iceArrowManaCost;
			}
			else {
				cout << "Недостаточно маны для огненного шара! Используем обычную атаку!" << endl;
				enemyCurrentHealth = enemyCurrentHealth - heroAttackPower;
			}
		}
		else if (enemyType == "Дракон") {
			cout << "Противник - Дракон!" << endl;

			if (heroCurrentMana - lightningStrikeManaCost >= 0) {
				cout << "Используем удар молнией!" << endl;
				enemyCurrentHealth = enemyCurrentHealth - (heroAttackPower * lightningStrikeMultiplierDamage);
				heroCurrentMana -= lightningStrikeManaCost;
			}
			else {
				cout << "Недостаточно маны для огненного шара! Используем обычную атаку!" << endl;
				enemyCurrentHealth = enemyCurrentHealth - heroAttackPower;
			}
		}
		else if (enemyType == "Призрак") {
			cout << "Противник - Призрак!" << endl;

			if (heroCurrentMana - ghostStrikeManaCost >= 0) {
				cout << "Используем призрачный удар!" << endl;
				enemyCurrentHealth = enemyCurrentHealth - (heroAttackPower * ghostStrikeMultiplierDamage);
				heroCurrentMana -= ghostStrikeManaCost;
			}
			else {
				cout << "Недостаточно маны для огненного шара! Используем обычную атаку!" << endl;
				enemyCurrentHealth = enemyCurrentHealth - heroAttackPower;
			}
		}
		else {
			cout << "Противник - неизвестен!" << endl;

			if (heroCurrentMana - fireballManaCost >= 0) {
				cout << "Используем огненный шар!" << endl;
				enemyCurrentHealth = enemyCurrentHealth - (heroAttackPower * fireballMultiplierDamage);
				heroCurrentMana -= fireballManaCost;
			}
			else {
				cout << "Недостаточно маны для огненного шара! Используем обычную атаку!" << endl;
				enemyCurrentHealth = enemyCurrentHealth - heroAttackPower;
			}
		}

		if (enemyCurrentHealth <= 0) {
			cout << "Победа!" << endl;
		}
		else {
			cout << "Противник еще жив! Отступаем!" << endl;
		}
	}		

	cout << endl << "Характеристики героя после боя: " << endl;
	cout << "Имя героя: " << heroName << endl;
	cout << "Уровень героя: " << heroLevel << endl;
	cout << "Количество жизни героя: " << heroCurrentHealth << endl;
	cout << "Количество маны героя: " << heroCurrentMana << endl;
	cout << "Сила урон героя: " << heroAttackPower << endl << endl;

	system("pause");
	system("cls");

	// ------------------------ Аптечка мага ------------------------
	// Задание: 
	// Рассчитай итоговое здоровье после использования зелья лечения.
	float healingPotion = 25.0f;
	
	cout << "Используем зелье лечения..." << endl;
	if (heroCurrentHealth + healingPotion > heroMaxHealth) {
		heroCurrentHealth = heroMaxHealth;
	}
	else {
		heroCurrentHealth += healingPotion;
	}

	cout << endl << "Характеристики героя после лечения: " << endl;
	cout << "Имя героя: " << heroName << endl;
	cout << "Уровень героя: " << heroLevel << endl;
	cout << "Количество жизни героя: " << heroCurrentHealth << endl;
	cout << "Количество маны героя: " << heroCurrentMana << endl;
	cout << "Сила урон героя: " << heroAttackPower << endl << endl;

	system("pause");
	system("cls");
}
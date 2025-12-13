#include "Player.h"
#include "Enemy.h"

Player::Player(string player_name, int player_health, int player_damage, int player_level)
{
    name = player_name;
    health = player_health;
    damage = player_damage;
    level = player_level;
}

// Реализация метода Attack после того, как Enemy полностью определен
void Player::Attack(Enemy& target) {
    target.TakeDamage(damage);
}

void Player::PrintStats() {
    cout << "Имя: " << name << endl;
    cout << "Здоровье: " << health << endl;
    cout << "Урон: " << damage << endl;
    cout << "Уровень: " << level << endl;
}

void Player::Heal(int amount) {
    health += amount;
}

void Player::TakeDamage(int damage_amount) {
    health -= damage_amount;
    if (health < 0)
        health = 0;
}

bool Player::IsAlive() {
    return health > 0;
}

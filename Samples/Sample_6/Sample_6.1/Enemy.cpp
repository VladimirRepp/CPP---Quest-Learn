#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(string enemy_type, int enemy_health, int enemy_damage, int enemy_level)
{
    type = enemy_type;
    health = enemy_health;
    damage = enemy_damage;
    level = enemy_level;
}

// Реализация метода Attack после того, как Player полностью определен
void Enemy::Attack(Player& target) {
    target.TakeDamage(damage);
}

void Enemy::PrintStats() {
    cout << "Тип: " << type << endl;
    cout << "Здоровья: " << health << endl;
    cout << "Урон: " << damage << endl;
    cout << "Уровень: " << level << endl;
}

void Enemy::Heal(int amount) {
    health += amount;
}

void Enemy::TakeDamage(int damage_amount) {
    health -= damage_amount;
    if (health < 0)
        health = 0;
}

bool Enemy::IsAlive() {
    return health > 0;
}
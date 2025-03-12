#include "Monster.hpp"
#include "Player.hpp"
#include <iostream>

void Monster::Start()
{
    health = 10;
    m_character = 'M';
}

void Monster::Update()
{
}

void Monster::Attack(Player& player)
{
    int damage = GetStats().strength;
    player.health -= damage;
    printf("The monster attacks you for %d damage!\n", damage);
}

void Bear::Start()
{
    health = 15;
    m_character = 'B';
    m_stats.strength = 5;
}

void Bear::Attack(Player& player)
{
    int damage = m_stats.strength;
    player.health -= damage;
    printf("The bear mauls you for %d damage!\n", damage);
}

void Wolf::Start()
{
    m_character = 'W';
    health = m_stats.constitution;
}

void Wolf::Attack(Player& player)
{
    int damage = m_stats.dexterity;
    player.health -= damage;
    printf("The wolf lunges at you and deals %d damage!\n", damage);
}

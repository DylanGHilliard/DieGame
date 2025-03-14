#include "Monster.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>  
#include <cmath>


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
    float dmgmulti = (rand() % 101 + 50) / 100.0f;
    int damage = static_cast<int>(m_stats.strength * dmgmulti);     
    player.health -= damage;
    printf("The monster attacks you for %d damage!\n", damage);
}

void Bear::Start()
{

    health = 15;
    m_character = 'B';
    m_stats.strength = 5 *  round(m_scale*0.5); 
}

void Bear::Attack(Player& player)
{
    float dmgmulti = (rand() % 101 + 50) / 100.0f;
    int damage = static_cast<int>(m_stats.strength * dmgmulti);     
    player.health -= damage;
    printf("The Bear attacks you for %d damage!\n", damage);
}

void Wolf::Start()
{
    health = 10;
    m_character = 'W';
    m_stats.dexterity = 5 * round(m_scale*0.5);
    
}

void Wolf::Attack(Player& player)
{
    float dmgmulti = (rand() % 101 + 50) / 100.0f;
    int damage = static_cast<int>(m_stats.dexterity * dmgmulti);     
    player.health -= damage;
    printf("The wolf lunges at you and deals %d damage!\n", damage);
}

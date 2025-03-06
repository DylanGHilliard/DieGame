#include "Monster.hpp"
#include "Room.hpp"


void Monster::Start()
{

    health = 10;
    m_character = 'M';
}

void Monster::Update()
{

}

void Bear::Start()
{
    health = 10;
    m_character = 'B';
}

void Wolf::Start()
{
   
    m_character = 'W';
    //m_stats.strength = 2 * room->roomCount;
    //m_stats.constitution = 2 * room->roomCount;
    health = m_stats.constitution;
}
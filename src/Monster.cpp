#include "Monster.hpp"
#include "Room.hpp"


void Monster::Start()
{
    m_character = 'M';
}

void Monster::Update()
{
 
}

void Bear::Start()
{
    m_character = 'B';
    health = 10;
}

void Wolf::Start()
{
    m_character = 'W';
    health = 10;
}
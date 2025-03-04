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
    m_character = 'B';
}

void Wolf::Start()
{
    m_character = 'W';
}
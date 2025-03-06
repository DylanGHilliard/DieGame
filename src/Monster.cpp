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
    health = 10;
    m_character = 'W';
}
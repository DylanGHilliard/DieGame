#pragma once

#include "Entity.hpp"

class Player : public Entity
{
public:
    int health = 10;
    void Start();
    void Update();
    void PrintStats();
private:
    int m_keyCount = 0;
    int m_goldCount = 0;
};
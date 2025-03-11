#pragma once

#include "Entity.hpp"

class Player : public Entity
{
public:
    int health = 10;
    void Start();
    void Update();
    void PrintStats();
    void UpdateStats();
private:
    int m_keyCount = 0;
    int m_goldCount = 0;
    bool m_isStart = true;
    int m_statPoints = 15;

};
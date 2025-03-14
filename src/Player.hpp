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
    void Dash(Vector2D _dir);
    void AddPoints(int _points) { m_statPoints += _points; }
private:
    int m_keyCount = 0;
    int m_goldCount = 0;
    bool m_isStart = true;
    int m_statPoints = 15;

};
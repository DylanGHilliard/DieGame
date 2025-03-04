#pragma once

#include "Entity.hpp"

class Monster : public Entity
{
public:
    int health;
    void Start();
    void Update();
private:
};


class Bear : Monster{
public:

private:
};

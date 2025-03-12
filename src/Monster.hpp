#pragma once
#include "Player.hpp"
#include "Entity.hpp"

class Monster : public Entity
{
public:
    int health;
    virtual void Start();
    virtual void Update();
    virtual void Attack(Player& player);
};

class Bear : public Monster
{
public:
    void Start() override;
    void Attack(Player& player) override;
};

class Wolf : public Monster
{
public:
    void Start() override;
    void Attack(Player& player) override;
};

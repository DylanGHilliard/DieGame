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


class Bear : public Monster{
public:
    void Start();
    //void Update();
private:
};

class Wolf : public Monster{
    public:
        void Start();
        //void Update();
    private:
    
    };

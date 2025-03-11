#include "Player.hpp"
#include "fogpi/fogpi.hpp"

#include "Room.hpp"
#include <time.h>

void Player::Start()
{
    m_character = 'P';
    m_stats.strength = 10;
    m_stats.constitution = 10;
    m_stats.dexterity = 10;
    m_stats.intelligence = 10;
    m_stats.wisdom = 10;
    m_stats.charisma = 10;
    health = m_stats.constitution *2;
}

void Player::Update()
{
    char directionInput;
    
    do {
        directionInput = request_char("wasd and Enter to move");
    } while (directionInput != 'w' &&
             directionInput != 'a' &&
             directionInput != 's' &&
             directionInput != 'd');
    
    Vector2D direction(0.0f);

    switch (directionInput)
    {
    case 'w':
        direction = {0.0f, -1.0f};
        break;
    case 'a':
        direction = {-1.0f, 0.0f};
        break;
    case 's':
        direction = {0.0f, 1.0f};
        break;
    case 'd':
        direction = {1.0f, 0.0f};
        break;
    default:
        direction = {0.0f, 1.0f};
        break;
    }

    Vector2D tryPos = m_position + direction;

    // Check for chest
    if (room->GetLocation(tryPos) == 'C')
    {
        if (m_keyCount >0){
            
            if (rand() % 2 == 0)
            {
                health += 2;
                printf("You found some healing potions: +2 health\n");
            }
            else{
                m_goldCount +=5;
                printf("You found some gold: +5 gold\n");
            }

            m_keyCount--;
            room->ClearLocation(tryPos);
            PrintStats();
        }
        else
        {
            printf("NO KEY!!!\n");
        }

    }

       // Check for monster encounter
       if (room->GetLocation(tryPos) == 'B' || room->GetLocation(tryPos) == 'W')
       {
            room->Fight(tryPos);
            return;
       }

    // check for a key
    if (room->GetLocation(tryPos) == 'K')
    {
        m_keyCount++;
        room->ClearLocation(tryPos);
    }

    if (room->GetLocation(tryPos) == 'L')
    {
        if (m_keyCount <= 0)
        {
            printf("NO KEY!!!\n");
            return;
        }

        m_keyCount--;
        room->SetLocation(tryPos, 'D');
        return;
    }
   
    // open door
    if (room->GetLocation(tryPos) == 'D')
    {
        room->OpenDoor(tryPos);
        if (int i = rand() % 2;  i == 0)
        {
            health += 5;
        }
        return;
    }

    if (room->GetLocation(tryPos) == ' ') 
        m_position = tryPos;
    
    printf("%c\n", directionInput);
}

void Player::PrintStats()
{
    printf("Health: %d\n", health);
    printf("Keys: %d\n", m_keyCount);
    printf("Gold: %d\n", m_goldCount);
}
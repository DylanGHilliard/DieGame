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

    if (m_isStart)
    {
        m_isStart = false;
        printf("Welcome to the dungeon!\n");
        UpdateStats();
        
    }
    
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

void Player::UpdateStats()
{
    while (m_statPoints>0)
    {
        printf("You have %d stat points to spend\n", m_statPoints);
        printf("Where would you like to put your points?\n");
        printf("1. Strength %d\n 2. Constitution %d\n 3. Dexterity %d\n 4. Intelligence %d\n 5. Wisdom %d \n 6. Charisma %d \n",m_stats.strength, m_stats.constitution, m_stats.dexterity, m_stats.intelligence, m_stats.wisdom, m_stats.charisma);
        int statChoice = request_int("Enter Stat Number to Increase");
        int statPoints = request_int("Enter the number of points to put into the stat");
        while (statPoints > m_statPoints)
        {
            printf("You don't have that many points to spend\n");
            statPoints = request_int("Enter the number of points to put into the stat");
        }

        switch (statChoice)
        {
        case 1:
            m_stats.strength+=statPoints;
            break;
        case 2:
            m_stats.constitution+=statPoints;
            break;
        case 3:
            m_stats.dexterity+=statPoints;
            break;
        case 4:
            m_stats.intelligence+=statPoints;
            break;
        case 5:
            m_stats.wisdom+=statPoints;
            break;
        case 6:
            m_stats.charisma+=statPoints;
            
            break;
        default:
            break;
        }
        m_statPoints -= statPoints;
    }


}
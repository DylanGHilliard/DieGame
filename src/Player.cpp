#include "Player.hpp"
#include "fogpi/fogpi.hpp"

#include "Room.hpp"
#include <time.h>

void Player::Start()
{
    m_character = 'P';
    health = m_stats.constitution;
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
    }

    if (room->GetLocation(tryPos) == ' ') 
        m_position = tryPos;
    
    printf("%c\n", directionInput);
}
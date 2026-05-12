//
//  Player2.cpp
//  Ping Pong (raylib)
//
//  Created by Khutso on 2025/01/21.
//

#include "Player2.hpp"

Player2::Player2() {}

void Player2::Update()
{
    if (IsKeyDown(KEY_W))
    {
        y = y - speed;
    }
    if (IsKeyDown(KEY_S))
    {
        y = y + speed;
    }
    
    LimitMovement();
}

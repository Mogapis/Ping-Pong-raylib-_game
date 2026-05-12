//
//  Cpu.cpp
//  Ping Pong (raylib)
//
//  Created by Khutso on 2025/01/21.
//

#include "Cpu.hpp"

CpuPaddle::CpuPaddle(){}

void CpuPaddle::Update(int ball_y)
{
    if (y + height/2 > ball_y)
    {
        y = y - speed;
    }
    if (y + height/2 <= ball_y)
    {
        y = y + speed;
    }
    
    LimitMovement();
}


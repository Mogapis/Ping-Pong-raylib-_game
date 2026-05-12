//
//  Ball.cpp
//  Ping Pong (raylib)
//
//  Created by Khutso on 2025/01/21.
//

#include "Ball.hpp"

int player1_score = 0;
int cpu_score = 0;
int player2_score = 0;

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

Ball::Ball(){}

void Ball::Draw()
{
    DrawCircle(x, y, 20, Yellow);
}

void Ball::Update()
{
    // The speed of the ball per distance covered
    x += speed_x;
    y += speed_y;
    
    if (y + radius >= GetScreenHeight() || y - radius <= 0)
    {
        speed_y *= -1;
    }
    if (x + radius >= GetScreenWidth())
    {
        cpu_score++;
        player2_score++;
        ResetBall();
    }
        
    if(x - radius <= 0)
    {
        player1_score++;
        ResetBall();
    }
}

void Ball::ResetBall()
{
    x = GetScreenWidth()/2;
    y = GetScreenHeight()/2;
    
    int speed_choices[2] = {1, -1};
    speed_x *= speed_choices[GetRandomValue(0, 1)];
    speed_y *= speed_choices[GetRandomValue(0, 1)];
}

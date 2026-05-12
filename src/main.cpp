//
//  main.cpp
//  Ping Pong (raylib)
//
//  Created by Khutso on 2025/01/21.
//

#include <iostream>

#include <raylib.h>
#include "components/Ball.hpp"
#include "components/Paddle.hpp"
#include "components/Cpu.hpp"
#include "components/Player2.hpp"

using namespace std;

extern Color Green;
extern Color Dark_Green;
extern Color Light_Green;
extern Color Yellow;

Ball ball;
Paddle player1;
Player2 player2;
CpuPaddle cpu;

// Load
Sound coSound = LoadSound("/Ping Pong (raylib)/Assets/sound/collisionSoundcopy.wav");



void InitPlayer1(Paddle &player1, int screen_width, int screen_height);
void InitPlayer2(Player2 &player2, int screen_width, int screen_height);
void InitCPU(CpuPaddle &cpu, int screen_width, int screen_height);

float lastCollisionTime = 0.0f;  // Variable to store the last time the collision sound was played

// Set the maximum duration for the sound (1 second)
const float soundDuration = 1.0f;

void PlayCollisionSound() {
    
    // Only play the sound if more than 'soundDuration' has passed since the last time
    if (GetTime() - lastCollisionTime >= soundDuration) {
        PlaySound(coSound);
        lastCollisionTime = GetTime();  // Update lastCollisionTime to the current time
    }
}

int main(int argc, const char * argv[]) {
    
       
    
    
    cout << "Starting the game...\n";
    
    int option = 0;
    
    cout << "----- Welcome to ME Pong Menu -----\n\n";
    
    const int screen_width = 1280; // Change this to 1280/1920 at the end of creating the game
    const int screen_height = 800; // Change this to 800/1080 at the end of creating the game
    
    InitWindow(screen_width, screen_height, "ME Pong");
    InitAudioDevice();
    SetSoundVolume(coSound, 1.0f);  // Set sound volume to maximum
    SetTargetFPS(60);
    
    ball.radius = 20;
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.speed_x = 7;
    ball.speed_y = 7;
   
    do {
        
        cout << "1. Player 1  vs  Player 2\n";
        cout << "2. Player 1  vs  CPU\n";
        cout << "3. Exit Game\n\n";
        
        cout << "Enter your option: ";
        cin >> option;
        
        switch (option) {
            case 1:
                InitPlayer1(player1, 1280, 800);
                InitPlayer2(player2, 1280, 800);
                
                while(WindowShouldClose() == false) {
                    BeginDrawing();
                    
                    // Update
                    ball.Update();
                    player1.Update();
                    
                    if (option == 1)
                    {
                        player2.Update();
                    }
                    
                    // Checking for collision
                    if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player1.x, player1.y, player1.width, player1.height} ))
                    {
                        ball.speed_x *= -1;
                        PlayCollisionSound();
                    }
                    
                    if (option == 1) {
                        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player2.x, player2.y, player2.width, player2.height} ))
                        {
                            ball.speed_x *= -1;
                            PlayCollisionSound();
                        }
                    }
                    
                    // Drawing
                    ClearBackground(Dark_Green);
                    DrawRectangle(screen_width/2, 0, screen_width/2, screen_height, Green);
                    DrawCircle(screen_width/2, screen_height/2, 150, Light_Green);
                    DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);
                    ball.Draw();
                    player1.Draw();
                    player2.Draw();
                    //cpu.Draw();
                    DrawText("Player 2", 4, 6, 50, RED);
                    DrawText("Player 1", 3*screen_width/4 -10, 35, 50, BLACK);
                    DrawText(TextFormat("%i",player2_score), screen_width/4 -20, 20, 80, WHITE);
                    DrawText(TextFormat("%i",player1_score), 3*screen_width/4 -20, 20, 80, WHITE);
                    
                    EndDrawing();
                    
                }
                
                //CloseWindow();
                break;
            case 2:
                InitCPU(cpu, 1280, 800);
                InitPlayer1(player1, 1280, 800);
                
                while(WindowShouldClose() == false) {
                    BeginDrawing();
                    
                    // Update
                    ball.Update();
                    player1.Update();
                    
                    if (option == 2)
                    {
                        cpu.Update(ball.y);
                    }
                    
                    // Checking for collision
                    if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player1.x, player1.y, player1.width, player1.height} ))
                    {
                        ball.speed_x *= -1;
                        PlayCollisionSound();
                    }
                    
                    if (option == 2) {
                        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height} ))
                        {
                            ball.speed_x *= -1;
                            PlayCollisionSound();
                        }
                    }
                    
                    // Drawing
                    ClearBackground(Dark_Green);
                    DrawRectangle(screen_width/2, 0, screen_width/2, screen_height, Green);
                    DrawCircle(screen_width/2, screen_height/2, 150, Light_Green);
                    DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);
                    ball.Draw();
                    player1.Draw();
                   // player2.Draw();
                    cpu.Draw();
                    DrawText("CPU", 4, 6, 50, RED);
                    DrawText("Player 1", 3*screen_width/4 -10, 35, 50, BLACK);
                    DrawText(TextFormat("%i",cpu_score), screen_width/4 -20, 20, 80, WHITE);
                    DrawText(TextFormat("%i",player1_score), 3*screen_width/4 -20, 20, 80, WHITE);
                    
                    EndDrawing();
                    
                }
                
               // CloseWindow();
                break;
                
            case 3:
                CloseAudioDevice();
                CloseWindow();
                
                cout << "Ending the game...\n";
                break;
            default:
                break;
        }
        
        
    } while (option != 3);
    
    return 0;
}

void InitPlayer1(Paddle &player1, int screen_width, int screen_height)
{
    player1.width = 25;
    player1.height = 120;
    player1.x = screen_width - player1.width - 10;
    player1.y = screen_height/2 - player1.height/2;
    player1.speed = 6;

}

void InitPlayer2(Player2 &player2, int screen_width, int screen_height)
{
    player2.width = 25;
    player2.height = 120;
    player2.x = 10;
    player2.y = screen_height/2 - player2.height/2;
    player2.speed = 6;
}

void InitCPU(CpuPaddle &cpu, int screen_width, int screen_height)
{
    cpu.width = 25;
    cpu.height = 120;
    cpu.x = 10;
    cpu.y = screen_height/2 - cpu.height/2;
    cpu.speed = 6;
}

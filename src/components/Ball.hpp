//
//  Ball.hpp
//  Ping Pong (raylib)
//
//  Created by Khutso on 2025/01/21.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <iostream>

#include <raylib.h>

using namespace std;


extern int player1_score;
extern int player2_score;
extern int cpu_score;

class Ball {
  
public:
    float x, y;
    int speed_x, speed_y;
    int radius;
    
    Ball();
    
    void Draw();
    void Update();
    void ResetBall();
};


#endif /* Ball_hpp */

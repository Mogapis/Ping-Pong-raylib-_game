//
//  Paddle.hpp
//  Ping Pong (raylib)

#ifndef Paddle_hpp
#define Paddle_hpp

#include <stdio.h>
#include <iostream>

#include <raylib.h>

class Paddle {
protected:
    void LimitMovement();
    
public:
    float x, y;
    float width, height;
    int speed;
    
    Paddle();
    void Draw();
    void Update();
};

#endif /* Paddle_hpp */

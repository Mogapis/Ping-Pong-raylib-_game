//
//  Paddle.hpp
//  Ping Pong (raylib)
//
//  Created by Khutso on 2025/01/21.
//

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

//
//  Cpu.hpp
//  Ping Pong (raylib)

#ifndef Cpu_hpp
#define Cpu_hpp

#include <stdio.h>
#include <iostream>

#include "Paddle.hpp"
#include "raylib.h"

class CpuPaddle: public Paddle{
public:
    CpuPaddle();
    void Update(int ball_y);
};

#endif /* Cpu_hpp */

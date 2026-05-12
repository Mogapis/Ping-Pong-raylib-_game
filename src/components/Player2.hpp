//
//  Player2.hpp
//  Ping Pong (raylib)
//
//  Created by Khutso on 2025/01/21.
//

#ifndef Player2_hpp
#define Player2_hpp

#include <stdio.h>
#include <iostream>

#include "Paddle.hpp"
#include "raylib.h"

using namespace std;

class Player2 : public Paddle
{
public:
    Player2();
    void Update();
};

#endif /* Player2_hpp */

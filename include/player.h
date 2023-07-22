//
// Created by rpurt on 22.07.2023.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include "controls.h"

class Player{
    char symbol = '@';
    int x_;
    int y_;
    Controls &controls;

    void Render();

    void Move();
public:
    Player(char symbol, int x, int y, Controls &controls) : symbol(symbol), x_(x), y_(y), controls(controls) {}

    void Update();
};


#endif //UNTITLED_PLAYER_H

//
// Created by rpurt on 22.07.2023.
//
#include <BearLibTerminal.h>
#include "player.h"
void Player::Move() {
    if (controls.IsMovingDown()){
        y_ += 1;
    }
    if (controls.IsMovingUp()){
        y_ -= 1;
    }
    if (controls.IsMovingLeft()){
        x_ -= 1;
    }
    if (controls.IsMovingRight()){
        x_ += 1;
    }
}
void Player::Render() { terminal_put(x_,y_,symbol);}
void Player::Update() {
    Move();
    Render();
}

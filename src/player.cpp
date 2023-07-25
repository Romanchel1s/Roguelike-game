//
// Created by rpurt on 22.07.2023.
//
#include "../include/player.h"

#include <BearLibTerminal.h>
void Player::Move() {
  if (controls.IsMovingDown()) {
    y_ += 1;
    stepcounter +=1;
  }
  if (controls.IsMovingUp()) {
    y_ -= 1;
    stepcounter +=1;
  }
  if (controls.IsMovingLeft()) {
    x_ -= 1;
    stepcounter +=1;
  }
  if (controls.IsMovingRight()) {
    x_ += 1;
    stepcounter +=1;
  }
}
void Player::Render() {
  terminal_put(x_, y_, symbol);
}
void Player::Update() {
  Move();
  Render();
  StepCount();
}
void Player::StepCount() {
  terminal_printf(10, 0, "steps: %d", stepcounter);
}
int Player::GetX() const {
  return x_;
}

int Player::GetY() const {
  return y_;
}


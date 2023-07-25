//
// Created by rpurt on 22.07.2023.
//
#include "../include/controls.h"

#include <BearLibTerminal.h>

void Controls::Update() {
  is_exit_ = false;
  is_movingleft_ = false;
  is_movingright_ = false;
  is_movingup_ = false;
  is_movingdown_ = false;

  while (terminal_has_input()) {
    auto key = terminal_read();
    if (key == TK_LEFT) {
      is_movingleft_ = true;
    }
    if (key == TK_RIGHT) {
      is_movingright_ = true;
    }
    if (key == TK_UP) {
      is_movingup_ = true;
    }
    if (key == TK_DOWN) {
      is_movingdown_ = true;
    }
    if (key == TK_CLOSE) {
      is_exit_ = true;
    }
  }
}
bool Controls::IsMovingLeft() const {
  return is_movingleft_;
}
bool Controls::IsMovingRight() const {
  return is_movingright_;
}
bool Controls::IsMovingDown() const {
  return is_movingdown_;
}
bool Controls::IsMovingUp() const {
  return is_movingup_;
}
bool Controls::IsExit() const {
  return is_exit_;
}

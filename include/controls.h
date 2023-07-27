//
// Created by rpurt on 22.07.2023.
//

#ifndef INCLUDE_CONTROLS_H_
#define INCLUDE_CONTROLS_H_

class Controls {
  bool is_exit_ = false;
  bool is_movingleft_ = false;
  bool is_movingright_ = false;
  bool is_movingup_ = false;
  bool is_movingdown_ = false;
 public:
  bool IsMovingLeft() const;
  bool IsMovingRight() const;
  bool IsMovingUp() const;
  bool IsMovingDown() const;
  bool IsExit() const;
  void Update();
};

#endif  // INCLUDE_CONTROLS_H_

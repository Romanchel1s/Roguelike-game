#include <vector>
#include <BearLibTerminal.h>
#include <cmath>
#include <iostream>

class Controls {
    bool is_exit_ = false;
    bool is_movingleft_ = false;
    bool is_movingright_ = false;
    bool is_movingup_ = false;
    bool is_movingdown_ = false;
public:
    bool IsMovingLeft() { return is_movingleft_; }
    bool IsMovingRight(){ return is_movingright_;}
    bool IsMovingUp() { return is_movingup_;}
    bool IsMovingDown() { return is_movingdown_;}
    bool IsExit() const { return is_exit_; }
    void Update() {
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
                is_movingdown_= true;
            }
            if (key == TK_CLOSE) {
                is_exit_ = true;
            }
        }
    }
};


class Player{
    char symbol = '@';
    int x_;
    int y_;
    Controls &controls;

    void Render() { terminal_put(x_,y_,symbol);}

    void Move() {
        if (controls.IsMovingDown()){
            y_ -= 1;
        }
        if (controls.IsMovingUp()){
            y_ += 1;
        }
        if (controls.IsMovingLeft()){
            x_ -= 1;
        }
        if (controls.IsMovingRight()){
            x_ += 1;
        }
    }
public:
    Player(char symbol, int x, int y, Controls &controls) : symbol(symbol), x_(x), y_(y), controls(controls) {}

    void Update(){
        Move();
        Render();
    }
};

int main(){
    terminal_open();
    terminal_refresh();

    Controls controls;
    Player player{'@',1,1,controls};

    while (true){
        terminal_clear();

        controls.Update();
        if (controls.IsExit()) {
            break;
        }

        player.Update();

        terminal_refresh();
    }

    terminal_close();
}

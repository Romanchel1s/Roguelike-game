#include <vector>
#include <BearLibTerminal.h>
#include <cmath>
#include <iostream>

#include "controls.h"
#include "player.h"

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

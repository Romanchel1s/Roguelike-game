#include <BearLibTerminal.h>
#include "../include/ld-manager.h"
#include "../src/luckydoor.cpp"
#include "vector"
#include <thread>
#include <chrono>

bool LDManager::DeathFromUnLucky() {
  if (death) {
    return true;
  } else {
    return false;
  }
}
void LDManager::Update() {
  std::vector<LuckyDoor> doorshelper;
  for (auto &o : doors) {
    if (player_.GetX() == o.x && player_.GetY() == o.y) {
      terminal_print(25, 20, "Вы попали на дверь удачи! попытайтесь пройти");
    }
    o.Update();
  }
}
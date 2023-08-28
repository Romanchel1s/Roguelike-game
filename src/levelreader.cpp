#include "../include/level1.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Config FirstLevel::ReadLevel(std::string way) {
  int n = 0;
  int j = 0;
  int k = 0;
  std::string line;
  setlocale(LC_ALL, "ru");
  std::ifstream in(way);  // окрываем файл для чтения
  if (in.is_open()) {
    while (getline(in, line)) {
      for (char a : line) {
        if (a == '#') {
          Vec2 wall{j, n};
          walls.push_back(wall);
        }
        if (a == '$') {
          Vec2 coin{j, n};
          coins.push_back(coin);
        }
        if (a == '%') {
          Vec2 feed{j, n};
          food.push_back(feed);
        }
        if (a == '>') {
          std::string level_name;
          k++;
          std::ifstream inlevel("../src/levels/level1/ways.txt");
          int i = 0;
          while (getline(inlevel, line) && i <= k) {
            level_name = line;
          }
          Vec2 door(j, n);
          doors.push_back(door);
        }
        if (a == 'E') {
          Vec2 E(j, n);
          enemy.push_back(E);
        }
        if (a == '@') {
          Vec2 pl(j, n);
          player.push_back(pl);
        }
        j++;
      }
      j = 0;
      n++;
    }
  }
  Config config(walls, coins, food, doors, enemy, player);
  in.close();  // закрываем файл
  return config;
}

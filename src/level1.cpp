#include "../include/level1.h"

#include <fstream>
#include <iostream>
#include <vector>


#include "BearLibTerminal.h"

Config FirstLevel::ReadLevel() {
  int n=0;
  int j=0;
  std::string line;
  setlocale(LC_ALL,"ru");
  std::ifstream in("../src/levels/level1.txt"); // окрываем файл для чтения
  if (in.is_open())
  {
    while (getline(in,line)){
      for (char a:line){
        if (a=='#'){
          Wall wall{j,n};
          walls.push_back(wall);
        }
        if (a=='$'){
          Coin coin{j,n};
          coins.push_back(coin);
        }
        if (a=='%'){
          Food feed{j,n};
          food.push_back(feed);
        }
        j++;
      }
      j=0;
      n++;
    }
  }
  Config config(walls,coins,food);
  in.close();     // закрываем файл
  return config;
}
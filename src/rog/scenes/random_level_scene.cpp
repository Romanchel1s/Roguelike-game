#include "rog/scenes/random_level_scene.h"

#include <rog/components/control_component.h>
#include <rog/systems/coin_collision_system.h>
#include <rog/systems/game_over_system.h>
#include <rog/systems/player_move_system.h>

#include <random>
#include <string>
#include <vector>

#include "../include/config.h"
#include "../include/levelreader.h"
#include "lib/math/vec2.h"
#include "rog/components/coin_component.h"
#include "rog/components/color_component.h"
#include "rog/components/door_component.h"
#include "rog/components/enemy_component.h"
#include "rog/components/enemy_control_component.h"
#include "rog/components/enemy_fight_component.h"
#include "rog/components/food_component.h"
#include "rog/components/interface_component.h"
#include "rog/components/obstacle_component.h"
#include "rog/components/texture_component.h"
#include "rog/components/transform_component.h"
#include "rog/components/wall_component.h"
#include "rog/systems/door_collision_system.h"
#include "rog/systems/enemy_move_system.h"
#include "rog/systems/fight_system.h"
#include "rog/systems/food_collision_system.h"
#include "rog/systems/movement_system.h"
#include "rog/systems/rendering_system.h"
#include "rog/systems/steps_count_system.h"
#include "rog/systems/wall_collision_system.h"

void RandomLevelScene::OnCreate() {
  LevelReader lr;
  Config config = lr.ReadLevel("../src/levels/level2.txt");
  std::vector<std::string> ways = {"win"};
  std::random_device random_device;         // Источник энтропии.
  std::mt19937 generator(random_device());  // Генератор случайных чисел.
  // (Здесь берется одно инициализирующее значение, можно брать больше)
  std::uniform_int_distribution<> distribution(5, 70);  // Равномерное распределение [10, 20]// Случайное число.
  std::uniform_int_distribution<> linerand(5, 15);  // Равномерное распределение [10, 20]// Случайное число.
  std::vector<Vec2> coins_config;
  std::vector<Vec2> enemy_config;
  std::vector<Vec2> walls_config;
  std::vector<Vec2> food_config;
  for (int i = 0; i <= distribution(generator); i++) {
    coins_config.push_back(Vec2{distribution(generator), linerand(generator)});
  }
  for (int i = 0; i <= distribution(generator); i++) {
    enemy_config.push_back(Vec2{distribution(generator), linerand(generator)});
  }
  for (int i = 0; i <= distribution(generator); i++) {
    walls_config.push_back(Vec2{distribution(generator), linerand(generator)});
  }
  for (int i = 0; i <= distribution(generator); i++) {
    food_config.push_back(Vec2{distribution(generator), linerand(generator)});
  }
  {
    auto player = engine.GetEntityManager()->CreateEntity();
    player->Add<TransformComponent>(ctx_->x_, ctx_->y_);
    player->Add<TextureComponent>('@');
    player->Add<InterfaceComponent>();
    player->Add<ControlComponent>(TK_UP, TK_DOWN, TK_LEFT, TK_RIGHT);
  }
  {
    for (Vec2& pos : coins_config) {
      auto coin = engine.GetEntityManager()->CreateEntity();
      coin->Add<TransformComponent>(pos.x, pos.y);
      coin->Add<TextureComponent>('$');
      coin->Add<ColorComponent>("green");
      coin->Add<CoinComponent>();
    }
  }
  {
    for (Vec2& pos : config.WallsConfig()) {
      auto wall = engine.GetEntityManager()->CreateEntity();
      wall->Add<TransformComponent>(pos.x, pos.y);
      wall->Add<TextureComponent>('#');
      wall->Add<WallComponent>();
    }
  }
  {
    for (Vec2& pos : walls_config) {
      auto wall = engine.GetEntityManager()->CreateEntity();
      wall->Add<TransformComponent>(pos.x, pos.y);
      wall->Add<TextureComponent>('#');
      wall->Add<WallComponent>();
    }
  }
  {
    for (Vec2& pos : food_config) {
      auto food = engine.GetEntityManager()->CreateEntity();
      food->Add<TransformComponent>(pos.x, pos.y);
      food->Add<TextureComponent>('%');
      food->Add<ColorComponent>("orange");
      food->Add<FoodComponent>();
    }
  }
  {
    for (Vec2& pos : enemy_config) {
      auto enemy = engine.GetEntityManager()->CreateEntity();
      enemy->Add<TransformComponent>(pos.x, pos.y);
      enemy->Add<TextureComponent>('E');
      enemy->Add<ColorComponent>("red");
      enemy->Add<ControlComponent>(TK_UP, TK_DOWN, TK_LEFT, TK_RIGHT);
      enemy->Add<EnemyFightComponent>(100, 6);
      enemy->Add<EnemyComponent>(3, pos.x, pos.y);
    }
  }
  {
    for (Vec2& pos : config.DoorsConfig()) {
      auto way = ways.back();
      std::cout << way << std::endl;
      auto door = engine.GetEntityManager()->CreateEntity();
      door->Add<TransformComponent>(pos.x, pos.y);
      door->Add<TextureComponent>('>');
      door->Add<DoorComponent>(way);
      ways.pop_back();
    }
  }
  auto sys = engine.GetSystemManager();
  sys->AddSystem<RenderingSystem>();
  sys->AddSystem<EnemyMoveSystem>(controls);
  sys->AddSystem<DoorCollisionSystem>(controls, ctx_);
  sys->AddSystem<PlayerMoveSystem>(controls, ctx_);
  sys->AddSystem<CoinCollisionSystem>();
  sys->AddSystem<FoodCollisionSystem>(ctx_);
  sys->AddSystem<StepsCountSystem>(controls, ctx_);
  sys->AddSystem<GameOverSystem>(ctx_);
  sys->AddSystem<FightSystem>(ctx_);
  sys->AddSystem<WallCollisionSystem>(controls);
}
void RandomLevelScene::OnRender() {
  engine.OnUpdate();
}
void RandomLevelScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
RandomLevelScene::RandomLevelScene(Context* const ctx, const Controls& controls) : IScene(ctx), controls(controls) {}

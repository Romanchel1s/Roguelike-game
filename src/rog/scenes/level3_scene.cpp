#include "rog/scenes/level3_scene.h"

#include <rog/components/control_component.h>
#include <rog/systems/coin_collision_system.h>
#include <rog/systems/game_over_system.h>
#include <rog/systems/player_move_system.h>

#include <string>
#include <vector>

#include "../include/config.h"
#include "../include/levelreader.h"
#include "lib/math/vec2.h"
#include "rog/components/coin_component.h"
#include "rog/components/coinbox_component.h"
#include "rog/components/color_component.h"
#include "rog/components/door_component.h"
#include "rog/components/enemy_component.h"
#include "rog/components/enemy_control_component.h"
#include "rog/components/enemy_fight_component.h"
#include "rog/components/food_component.h"
#include "rog/components/interface_component.h"
#include "rog/components/key_component.h"
#include "rog/components/obstacle_component.h"
#include "rog/components/texture_component.h"
#include "rog/components/transform_component.h"
#include "rog/components/wall_component.h"
#include "rog/systems/coinbox_collision_system.h"
#include "rog/systems/door_collision_system.h"
#include "rog/systems/enemy_move_system.h"
#include "rog/systems/fight_system.h"
#include "rog/systems/food_collision_system.h"
#include "rog/systems/movement_system.h"
#include "rog/systems/rendering_system.h"
#include "rog/systems/steps_count_system.h"
#include "rog/systems/wall_collision_system.h"

void ThirdLevelScene::OnCreate() {
  LevelReader lr;
  Config config = lr.ReadLevel("../src/levels/level3.txt");
  std::vector<std::string> ways = {"win", "level2"};
  {
    // for (Vec2& pos : config.PlayerConfig()) {
    auto player = engine.GetEntityManager()->CreateEntity();
    player->Add<TransformComponent>(ctx_->x_ + 1, ctx_->y_ + 1);
    player->Add<TextureComponent>('@');
    player->Add<InterfaceComponent>();
    player->Add<ControlComponent>(TK_UP, TK_DOWN, TK_LEFT, TK_RIGHT);
    //  }
  }
  {
    for (Vec2& pos : config.CoinsConfig()) {
      auto coin = engine.GetEntityManager()->CreateEntity();
      coin->Add<TransformComponent>(pos.x, pos.y);
      coin->Add<TextureComponent>('$');
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
    for (Vec2& pos : config.FoodConfig()) {
      auto food = engine.GetEntityManager()->CreateEntity();
      food->Add<TransformComponent>(pos.x, pos.y);
      food->Add<TextureComponent>('%');
      food->Add<ColorComponent>("orange");
      food->Add<FoodComponent>();
    }
  }
  {
    for (Vec2& pos : config.EnemyConfig()) {
      auto enemy = engine.GetEntityManager()->CreateEntity();
      enemy->Add<TransformComponent>(pos.x, pos.y);
      enemy->Add<TextureComponent>('E');
      enemy->Add<ColorComponent>("blue");
      enemy->Add<ControlComponent>(TK_UP, TK_DOWN, TK_LEFT, TK_RIGHT);
      enemy->Add<EnemyFightComponent>(100, 6);
      enemy->Add<EnemyComponent>(20, pos.x, pos.y);
      enemy->Add<KeyComponent>();
    }
  }
  {
    for (Vec2& pos : config.CoinBoxConfig()) {
      auto box = engine.GetEntityManager()->CreateEntity();
      box->Add<TransformComponent>(pos.x, pos.y);
      box->Add<TextureComponent>('&');
      box->Add<CoinBoxComponent>();
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
      door->Add<KeyComponent>();
      ways.pop_back();
    }
  }
  auto sys = engine.GetSystemManager();
  sys->AddSystem<RenderingSystem>(ctx_);
  sys->AddSystem<EnemyMoveSystem>(controls);
  sys->AddSystem<PlayerMoveSystem>(controls, ctx_);
  sys->AddSystem<CoinCollisionSystem>(ctx_);
  sys->AddSystem<FoodCollisionSystem>(ctx_);
  sys->AddSystem<DoorCollisionSystem>(controls, ctx_);
  sys->AddSystem<StepsCountSystem>(controls, ctx_);
  sys->AddSystem<GameOverSystem>(ctx_);
  sys->AddSystem<FightSystem>(ctx_);
  sys->AddSystem<CoinBoxCollisionSystem>(ctx_);
  sys->AddSystem<WallCollisionSystem>(controls);
}
void ThirdLevelScene::OnRender() {
  engine.OnUpdate();
}
void ThirdLevelScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
ThirdLevelScene::ThirdLevelScene(Context* const ctx, const Controls& controls) : IScene(ctx), controls(controls) {}

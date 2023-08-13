#include "rog/scenes/game_scene.h"

#include <rog/components/control_component.h>
#include <rog/systems/coin_collision_system.h>
#include <rog/systems/game_over_system.h>
#include <rog/systems/player_move_system.h>

#include <vector>

#include "../include/config.h"
#include "../include/level1.h"
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

void GameScene::OnCreate() {
  FirstLevel fl;
  Config config = fl.ReadLevel();
  {
    auto player = engine.GetEntityManager()->CreateEntity();
    player->Add<TransformComponent>(0, 14);
    player->Add<TextureComponent>('@');
    player->Add<InterfaceComponent>();
    player->Add<ControlComponent>(TK_UP, TK_DOWN, TK_LEFT, TK_RIGHT);
  }
  {
    for (Vec2& pos : config.CoinsConfig()) {
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
    for (Vec2& pos : config.FoodConfig()) {
      auto food = engine.GetEntityManager()->CreateEntity();
      food->Add<TransformComponent>(pos.x, pos.y);
      food->Add<TextureComponent>('%');
      food->Add<ColorComponent>("orange");
      food->Add<FoodComponent>();
    }
  }
  {
    auto enemy = engine.GetEntityManager()->CreateEntity();
    enemy->Add<TransformComponent>(6, 6);
    enemy->Add<TextureComponent>('E');
    enemy->Add<ColorComponent>("red");
    enemy->Add<ControlComponent>(TK_UP, TK_DOWN, TK_LEFT, TK_RIGHT);
    enemy->Add<EnemyFightComponent>(100, 6);
    enemy->Add<EnemyComponent>(3, 6, 6);
  }
  {
    auto door = engine.GetEntityManager()->CreateEntity();
    door->Add<TransformComponent>(5, 5);
    door->Add<TextureComponent>('>');
    door->Add<DoorComponent>();
  }
  auto sys = engine.GetSystemManager();
  sys->AddSystem<RenderingSystem>();
  sys->AddSystem<PlayerMoveSystem>(controls);
  sys->AddSystem<CoinCollisionSystem>();
  sys->AddSystem<FoodCollisionSystem>(ctx_);
  sys->AddSystem<DoorCollisionSystem>(ctx_);
  sys->AddSystem<StepsCountSystem>(controls, ctx_);
  sys->AddSystem<GameOverSystem>(ctx_);
  sys->AddSystem<EnemyMoveSystem>(controls);
  sys->AddSystem<FightSystem>(ctx_);
  sys->AddSystem<WallCollisionSystem>(controls);
}
void GameScene::OnRender() {
  engine.OnUpdate();
}
void GameScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
GameScene::GameScene(Context* const ctx, const Controls& controls) : IScene(ctx), controls(controls) {}

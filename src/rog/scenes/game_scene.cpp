#include "rog/scenes/game_scene.h"

#include <rog/components/collider_component.h>
#include <rog/components/jump_component.h>
#include <rog/components/player_control_component.h>
#include <rog/systems/collision_system.h>
#include <rog/systems/game_over_system.h>
#include <rog/systems/jump_control_system.h>

#include "lib/math/vec2.h"
#include "rog/components/movement_component.h"
#include "rog/components/obstacle_component.h"
#include "rog/components/texture_component.h"
#include "rog/components/transform_component.h"
#include "rog/systems/movement_system.h"
#include "rog/systems/rendering_system.h"

/**
 * На каждую игровую сцену приходится свой набор сущностей и систем
 * Так, например, здесь у нас есть сущности игрока, кактусов и земли,
 * у каждой сущнности есть свой набор компонентов
 * (обратите внимание, что и аргументы у каждого соответствующие)
 *
 * После инициализации всех сущностей (а они хранятся в движке ECS),
 * происходит инициализация всех необходимых систем. Как и сущности,
 * они хранятся в движке ECS. Благодаря этому, при вызове OnUpdate()
 * у сцены достаточно вызвать только обновление движка ECS
 *
 * После того, как сцена заканчивает свою работу, содержимое движка ECS
 * очищается, чтобы другая сцена могла заполнить его своими компонентам
 * и системами
 */
void GameScene::OnCreate() {
  {
    auto player = engine.GetEntityManager()->CreateEntity();
    player->Add<TransformComponent>(0, ground_y_ - 1);
    player->Add<TextureComponent>('@');
    player->Add<MovementComponent>(ZeroVec2, UpVec2);
    player->Add<JumpComponent>(4.5, gravity_ * 3, ground_y_);
    player->Add<PlayerControlComponent>(TK_UP, TK_DOWN, TK_LEFT, TK_RIGHT);
    player->Add<ColliderComponent>(OnesVec2, ZeroVec2);
  }
  auto sys = engine.GetSystemManager();
  sys->AddSystem<RenderingSystem>();
  sys->AddSystem<MovementSystem>();
  sys->AddSystem<JumpControlSystem>(controls);
  sys->AddSystem<CollisionSystem>();
  sys->AddSystem<GameOverSystem>(ctx_);
}
void GameScene::OnRender() {
  engine.OnUpdate();
}
void GameScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
GameScene::GameScene(Context* const ctx, const Controls& controls) : IScene(ctx), controls(controls) {}

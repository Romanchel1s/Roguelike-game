#ifndef INCLUDE_ROG_COMPONENTS_COLLIDER_COMPONENT_H_
#define INCLUDE_ROG_COMPONENTS_COLLIDER_COMPONENT_H_

#include <lib/ecs/component.h>
#include <lib/math/vec2.h>
#include <set>

class Entity;

/**
 * Данный компонент - идеальный пример компонента с состоянием
 * Во множестве собирается информация о том, с кем произошло столкновение,
 * которое затем анализируется системой коллизий
 */
class ColliderComponent : public IComponent {
  std::set<Entity*> collisions_{};

 public:
  Vec2 size_;
  Vec2 offset_;

  explicit ColliderComponent(const Vec2& size, const Vec2& offset = ZeroVec2) : size_(size), offset_(offset) {}

  const std::set<Entity*>& GetCollisions() const {
    return collisions_;
  }

  bool AnyCollisions() const {
    return !collisions_.empty();
  }

  void Collide(Entity* entity) {
    collisions_.insert(entity);
  }

  void Clear() {
    collisions_.clear();
  }
};

#endif  // INCLUDE_ROG_COMPONENTS_COLLIDER_COMPONENT_H_

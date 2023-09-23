#ifndef INCLUDE_LIB_ECS_ENTITY_MANAGER_H_
#define INCLUDE_LIB_ECS_ENTITY_MANAGER_H_

#include <iostream>
#include <map>
#include <memory>
#include "lib/ecs/entity.h"

/**
 * Непосредственно класс, отвечающий за все сущности.
 * В его обязанности входит:
 * - создание и удаление сущностей
 * - хранение этих сущностей
 * - получение сущностей по уникальному ID
 */
class EntityManager {
 private:
  std::map<size_t, std::unique_ptr<Entity>> entities_;
  // TODO: maybe add tag system?
  size_t last_entity_id = 1;  // start from 1 to use 0 as a special entity ID

 public:
  Entity* CreateEntity() {
    auto id = ++last_entity_id;
    entities_.emplace(id, std::make_unique<Entity>(id));
    return entities_.at(id).get();
  }
  EntityManager* DeleteEntity(size_t id) {
    entities_.erase(id);
    return this;
  }
  EntityManager* DeleteAll() {
    entities_.clear();
    return this;
  }
  Entity* Get(size_t id) const {
    if (entities_.count(id) == 0) {
      std::cout << "[WARNING] there is no entity with id=" << id << std::endl;
      return nullptr;
    }
    return entities_.at(id).get();
  }

  // TODO: we need a method for fast lookup by some tag
  // Entity* Get(std::string name) const {
  // }

  /**
   * Необходим для того, чтобы не выставлять на показ
   * внутреннюю структуру менеджера при итерировании
   * по сущностям
   */
  class Iterator {
    std::map<size_t, std::unique_ptr<Entity>>::iterator iterator_;

   public:
    explicit Iterator(const std::map<size_t, std::unique_ptr<Entity>>::iterator& iterator) : iterator_(iterator) {}

    Iterator operator++() {
      iterator_.operator++();
      return *this;
    }
    Iterator operator++(int step) {
      iterator_.operator++(step);
      return *this;
    }

    Entity& operator*() {
      return *iterator_.operator*().second;
    }

    Entity* operator->() {
      return iterator_.operator*().second.get();
    }

    bool operator==(const Iterator& rhs) {
      return iterator_ == rhs.iterator_;
    }
    bool operator!=(const Iterator& rhs) {
      return iterator_ != rhs.iterator_;
    }
  };

  Iterator begin() {
    return Iterator{entities_.begin()};
  }

  Iterator end() {
    return Iterator{entities_.end()};
  }
};

#endif  // INCLUDE_LIB_ECS_ENTITY_MANAGER_H_

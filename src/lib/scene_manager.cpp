#include "lib/scenes/scene_manager.h"
#include <iostream>
#include <string>

void SceneManager::OnRender() {
  if (ctx_.scene_ != current_scene_) {
    std::cout << "Transition from '" << ctx_.scene_ << "' to '" << current_scene_ << "'" << std::endl;
    if (scenes_.count(current_scene_) != 0) {
      scenes_.at(current_scene_)->OnExit();
    }
    current_scene_ = ctx_.scene_;
    scenes_.at(current_scene_)->OnCreate();
  }
  if (scenes_.count(current_scene_) != 0) {
    scenes_.at(current_scene_)->OnRender();
  } else {
    std::cout << "[WARNING] Cannot update scene_ '" << current_scene_ << "': it doesn't exist." << std::endl;
  }
}

void SceneManager::OnExit() const {
  if (scenes_.count(current_scene_) != 0) {
    scenes_.at(current_scene_)->OnExit();
  }
}
void SceneManager::Put(const std::string& name, IScene* const scene) {
  scenes_[name] = std::unique_ptr<IScene>(scene);
}
SceneManager::SceneManager(const Context& ctx) : ctx_(ctx) {}

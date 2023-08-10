#ifndef INCLUDE_LIB_SCENES_SCENE_MANAGER_H_
#define INCLUDE_LIB_SCENES_SCENE_MANAGER_H_

#include <map>
#include <memory>
#include <string>
#include "lib/scenes/context.h"
#include "lib/scenes/i_scene.h"

/**
 * Менеджер сцен управляет жизненным циклом сцен:
 * - какая сцена должна быть сейчас запущена: OnCreate
 * - какая сцена сейчас должна рендериться: OnRender
 * - какая сцена сейчас должна быть остановлена: OnExit
 *
 * Менеджер владеет, но не создает объекты сцен.
 * Именно поэтому функция Put принимает указатель, но в словаре scenes_ хранится unique_ptr,
 * который автоматичски вызовет деструктор над всем сценами.
 *
 * Переключение между сценами производится с помощью выставления поля scene_ в контексте.
 */
class SceneManager {
  std::map<std::string, std::unique_ptr<IScene>> scenes_;
  const Context& ctx_;
  std::string current_scene_ = "";

 public:
  explicit SceneManager(const Context& ctx);

  void OnRender();
  void OnExit() const;

  /**
   * Функция для добавления новой сцены в менеджер
   * @param name имя сцены
   * @param scene указатель на сцену
   */
  void Put(const std::string& name, IScene* scene);
};

#endif  // INCLUDE_LIB_SCENES_SCENE_MANAGER_H_

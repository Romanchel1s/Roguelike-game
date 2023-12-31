#ifndef INCLUDE_LIB_SCENES_CONTEXT_H_
#define INCLUDE_LIB_SCENES_CONTEXT_H_

#include <string>
#include <vector>

/**
 * В контексте хранится информация о сцене, которую нужно сейчас отрисоватывать.
 * Контекст должен создаться где-то во вне и передаться по указателю во все сцены,
 * чтобы они могли им манипулировать и в SceneManager,
 * чтобы он мог читать из него информацию о сценах.
 *
 * Кстати, можно использовать контекст для хранения некоторой информации при переходе между сценами.
 * Но рекомендуется придумать механизм, чтобы не пришлось постоянно править класс контектса.
 * Как минимум используйте map<string, iobject*>
 */
class Context {
 public:
  std::string scene_ = "";
  int coins = 0;
  int steps = 0;
  std::vector<int> leaderBord;
  bool key = false;
  int x_ = 5;
  int y_ = 5;
  bool graphics = false;
};

#endif  // INCLUDE_LIB_SCENES_CONTEXT_H_

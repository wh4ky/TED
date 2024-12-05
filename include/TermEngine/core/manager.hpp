/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <csignal>
#include <mutex>

#include <TermEngine/core/process_manager_class.hpp>

namespace TE {
class ResourceManager {
private:
  static ResourceManager* instancePtr;
  static std::mutex mtx;
  ResourceManager() = default;

public:
  std::vector<std::unique_ptr<ProcessManager>> managers;
  ResourceManager(const ResourceManager& obj) = delete;
  
  void initManager(std::unique_ptr<ProcessManager> manager);

  static ResourceManager* getInstance();
  ~ResourceManager() = default;
};
} // namespace TE

#endif // MANAGER_HPP

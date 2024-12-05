/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#include <TermEngine/core/manager.hpp>

void TE::ResourceManager::initManager(std::unique_ptr<ProcessManager> manager) {
  managers.push_back(std::move(manager));
}

TE::ResourceManager* TE::ResourceManager::getInstance() {
  if (instancePtr == nullptr) {
    std::lock_guard<std::mutex> lock(mtx);
    if (instancePtr == nullptr) {
      instancePtr = new ResourceManager();
    }
  }
  return instancePtr;
}

TE::ResourceManager* TE::ResourceManager::ResourceManager::instancePtr = nullptr;
std::mutex TE::ResourceManager::mtx;

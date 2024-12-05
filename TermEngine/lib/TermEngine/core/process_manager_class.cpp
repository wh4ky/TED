/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#include <TermEngine/core/process_manager_class.hpp>

TE::ProcessManager::ProcessManager(const std::vector<std::string>& processNames) {
  for (const std::string &name : processNames) {
    processes.push_back(std::make_unique<Process>());
  }
};

TE::ProcessManager::~ProcessManager() {
  for (std::unique_ptr<Process> &process : processes) {
    process.reset();
  }
};

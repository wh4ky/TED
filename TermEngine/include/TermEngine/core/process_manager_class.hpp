/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#ifndef PROCESS_MANAGER_CLASS_HPP
#define PROCESS_MANAGER_CLASS_HPP

#include <vector>
#include <string>
#include <memory>

#include <TermEngine/core/process_class.hpp>

namespace TE {
class ProcessManager {
private:
  std::vector<std::unique_ptr<Process>> processes;

public:
  ProcessManager(const std::vector<std::string>& processNames);
  ~ProcessManager();
};
}

#endif // PROCESS_MANAGER_CLASS_HPP

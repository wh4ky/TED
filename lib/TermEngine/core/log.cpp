/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#include <TermEngine/core/log.hpp>

std::ofstream TE::log::logFile;
std::string TE::log::logFileName;

std::string TE::log::getTime() {
  std::time_t now = std::time(nullptr);
  std::tm *time = std::localtime(&now);
  return ((time->tm_hour < 10) ? "0" + std::to_string(time->tm_hour)
                               : std::to_string(time->tm_hour)) +
         ":" +
         ((time->tm_min < 10) ? "0" + std::to_string(time->tm_min)
                              : std::to_string(time->tm_min)) +
         ":" +
         ((time->tm_sec < 10) ? "0" + std::to_string(time->tm_sec)
                              : std::to_string(time->tm_sec));
}

std::string TE::log::getDate() {
  std::time_t now = std::time(nullptr);
  std::tm *time = std::localtime(&now);
  return ((time->tm_mday < 10) ? "0" + std::to_string(time->tm_mday)
                               : std::to_string(time->tm_mday)) +
         "/" +
         ((time->tm_mon < 9) ? "0" + std::to_string(time->tm_mon + 1)
                             : std::to_string(time->tm_mon + 1)) +
         "/" + (std::to_string(time->tm_year + 1900));
}

void TE::log::writeToFile(const std::string &string) {
  if (!logFile.is_open()) {
    std::cerr << "Failed to open log file" << std::endl;
    return;
  }

  std::string out = "[" + getTime() + "] " + string + "\n";

  logFile << out;
}

void TE::log::openLog() {
  if (!logFile) {
    try {
      logFileName = getTime() + "_" + getDate();
    } catch (...) {
      std::cerr << "\"logFileName\" wasn't created, can't create \"logFile\"."
                << std::endl;
      return;
    }
    try {
      logFile.open(logFileName);
    } catch (...) {
      std::cerr << "\"logFile\" can't be created." << std::endl;
      return;
    }
  } else {
    std::cerr << "\"logFile\" already exists." << std::endl;
    return;
  }
}

void TE::log::closeLog() {
  if (logFile.is_open()) {
    logFile.close();
  }
}

template <typename First, typename... Rest>
void TE::log::toFile(std::ostringstream &oss, First arg, const Rest &...rest) {
  oss << arg;

  if constexpr (sizeof...(rest) > 0) {
    log(oss, rest...);
  } else {
    writeToFile(oss.str());
  }
}

template <typename... Args> void TE::log::toFile(Args... args) {
  std::ostringstream oss;
  log(oss, args...);
}

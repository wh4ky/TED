/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#ifndef LOG_HPP
#define LOG_HPP

#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

namespace TE {
class log {
private:
  static std::ofstream logFile;
  static std::string logFileName;
  static std::string getTime();
  static std::string getDate();
  static void writeToFile(const std::string &string);

public:
  static void openLog();
  static void closeLog();

  template <typename First, typename... Rest>
  static void toFile(std::ostringstream &oss, First arg, const Rest &...rest);
  template <typename... Args> static void toFile(Args... args);
};
} // namespace TE

#endif // LOG_HPP

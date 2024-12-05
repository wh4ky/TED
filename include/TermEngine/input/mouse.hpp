/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <iostream>
#include <signal.h>
#include <string>
#include <termios.h>
// #include <tuple>
#include <unistd.h>

#include <TermEngine/core.hpp>

namespace TE {
class IO {
private:
  static struct termios original;
  static void signalHandle(int signum);
  static void disableMouseReporting(); 
  static void enableMouseReporting(); 
  static void revertTerminal();

public:
  IO();
  ~IO();

  void revertSettings();
  std::string getKey();
};

/*
std::tuple getMouse() { Function to get mouse clicks
  char buf[32];
  int bytesRead = read(STDIN_FILENO, buf, sizeof(buf) - 1);

  if (bytesRead <= 1) {
    buf[bytesRead] = '\0';

    for (int i = 0; i < bytesRead; ++i) {
      printf("%c ", buf[i]);
    }
    std::cout.flush();

    std::string str(buf);
    return str;
  }
  return "null";
}
*/

}

#endif // MOUSE_HPP

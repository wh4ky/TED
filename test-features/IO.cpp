// TEST do not use

#include <iostream>
#include <signal.h>
#include <string>
#include <termios.h>
#include <tuple>
#include <unistd.h>

namespace TE {
class IO {
private:
  static struct termios original;

  static void signalHandle(int signum) {
    revertTerminal();
    disableMouseReporting();
    exit(0);
  }

  static void disableMouseReporting() {
    //std::cout << "\033[?1003l";
    //std::cout.flush();
    std::cout << "\033[?1006l";
    std::cout.flush();
  }

  static void enableMouseReporting() {
    //std::cout << "\033[?1003h";
    //std::cout.flush();
    std::cout << "\033[?1006h";
    std::cout.flush();
  }

  static void revertTerminal() {
    original.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &original);
  }

public:
  IO() {
    signal(SIGINT, signalHandle);
    enableMouseReporting();

    tcgetattr(STDIN_FILENO, &original);
    struct termios raw = original;
    raw.c_lflag &= ~(ICANON | ECHO);
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
  }

  ~IO() {
    revertTerminal();
    disableMouseReporting();
  }

  void revertSettings() {
    revertTerminal();
    disableMouseReporting();
  }

  std::string getKey() {// function to get single keys (To Do: F-row and other keys)
    disableMouseReporting();
    char buf[3];
    int bytesRead = read(STDIN_FILENO, buf, sizeof(buf) - 1);
    buf[bytesRead] = '\0';

    std::string str(buf);

    /*for (int i = 0; i < 10; i++) {
      std::cout << buf[i] << std::endl;
    }*/

    //std::cout << std::dec << "control: " << str << std::endl;

    return str;
  }
};

/* std::tuple getMouse() { Function to get mouse clicks
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
};*/

struct termios IO::original;
} // namespace TE

int main() {
  TE::IO io;

  while (true) {
    std::string key = io.getKey(); // Read the key once

    if (key == "q") {
      io.revertSettings();
      return 0;
    } else if (key != "null") {
      std::cout << key << std::endl; // Output the key
    }

    usleep(1000);
  }

  io.revertSettings();
  return 0;
}

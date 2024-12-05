/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#include <TermEngine/input/mouse.hpp>

void TE::IO::disableMouseReporting() {
  // std::cout << "\033[?1003l";
  // std::cout.flush();
  std::cout << "\033[?1006l";
  std::cout.flush();
}

void TE::IO::enableMouseReporting() {
  // std::cout << "\033[?1003h";
  // std::cout.flush();
  std::cout << "\033[?1006h";
  std::cout.flush();
}

void TE::IO::revertTerminal() {
  original.c_lflag |= (ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &original);
}

TE::IO::IO() {
  signal(SIGINT, signalHandle);
  enableMouseReporting();

  tcgetattr(STDIN_FILENO, &original);
  struct termios raw = original;
  raw.c_lflag &= ~(ICANON | ECHO);
  raw.c_cc[VMIN] = 1;
  raw.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

TE::IO::~IO() {
  revertTerminal();
  disableMouseReporting();
}

void TE::IO::revertSettings() {
  revertTerminal();
  disableMouseReporting();
}

std::string TE::IO::getKey() {// function to get single keys (To Do: F-row and other keys)
  disableMouseReporting();
  char buf[3];
  int bytesRead = read(STDIN_FILENO, buf, sizeof(buf) - 1);
  buf[bytesRead] = '\0';

  std::string str(buf);
  return str;
}

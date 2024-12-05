/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <TermEngine/core.hpp>
#include <new>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

namespace TE {
class Screen {
private:
  std::vector<std::vector<std::string>> *video;
  int y_height;
  int x_width;

public:
  Screen(int x, int y);
  ~Screen();
  void clear();
  void cellSet(int x, int y, std::string new_value);
  void update();
  void fill();
};
} // namespace TE

#endif // VIDEO_HPP

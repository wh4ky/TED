/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#include <TermEngine/video/video.hpp>

TE::Screen::Screen(int x, int y) : x_width(x), y_height(y) {
  try {
    video = new std::vector<std::vector<std::string>>(
        x_width, std::vector<std::string>(y_height));
  } catch (...) {
    TE::log::toFile("FATAL ERROR: couldn't allocate video buffer.");
    throw std::runtime_error("FATAL ERROR: couldn't allocate video buffer.");
  }
}

TE::Screen::~Screen() { delete video; }

void TE::Screen::clear() { printf("\033[0;0H\033[0J"); }

void TE::Screen::cellSet(int x, int y, std::string new_value) {
  try {
    (*video)[y][x] = new_value;
  } catch (std::out_of_range) {
    TE::log::toFile("WARNING: " + std::to_string(x) + ", " +
                     std::to_string(y) + " is out of range.");
    return;
  } catch (...) {
    TE::log::toFile("WARNING: Couldn't write pixel " + new_value + " to " +
                     std::to_string(x) + ", " + std::to_string(y) + ".");
    return;
  }
}

void TE::Screen::update() {
  for (int i = 0; i < y_height; i++) {
    for (int j = 0; j < x_width; j++) {
      printf("%s", (*video)[i][j].c_str());
      if (j == x_width - 1) {
        printf("\n");
      }
    }
  }
  printf("\n");
}

void TE::Screen::fill() {
  for (int i = 0; i < y_height; i++) {
    for (int j = 0; j < x_width; j++) {
      try {
        (*video)[i][j] = ".";
      } catch (std::out_of_range) {
        TE::log::toFile("WARNING: Cell " + std::to_string(j) + ", " +
                         std::to_string(i) + " is out of range, can't fill.");
      } catch (...) {
        TE::log::toFile("WARNING: Couldn't fill video buffer at " +
                         std::to_string(j) + ", " + std::to_string(i) + ".");
      }
    }
  }
}

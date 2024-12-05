/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#include <TermEngine/video/color.hpp>

std::string const TE::color::esc = "\033[";
std::string const TE::color::foregroundPrefix = "38;";
std::string const TE::color::backgroundPrefix = "48;";
std::string const TE::color::eightBitPrefix = "5;";
std::string const TE::color::rgbPrefix = "2;";

std::string TE::color::background(const unsigned int &color) { // 8-bit
  return esc + foregroundPrefix + eightBitPrefix + std::to_string(color) + "m";
}

std::string TE::color::foreground(const unsigned int &color) { // 8-bit
  return esc + backgroundPrefix + eightBitPrefix + std::to_string(color) + "m";
}

std::string TE::color::background(const unsigned int &red,
                                  const unsigned int &green,
                                  const unsigned int &blue) { // rgb
  return esc + foregroundPrefix + rgbPrefix + std::to_string(red) + ";" +
         std::to_string(green) + ";" + std::to_string(blue) + "m";
}

std::string TE::color::foreground(const unsigned int &red,
                                  const unsigned int &green,
                                  const unsigned int &blue) { // rgb
  return esc + backgroundPrefix + rgbPrefix + std::to_string(red) + ";" +
         std::to_string(green) + ";" + std::to_string(blue) + "m";
}
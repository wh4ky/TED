/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#ifndef COLOR_HPP
#define COLOR_HPP

#include <TermEngine/core.hpp>
#include <cstdio>
#include <string>

namespace TE {
class color {
protected:
  static const std::string esc;
  static const std::string foregroundPrefix;
  static const std::string backgroundPrefix;
  static const std::string eightBitPrefix;
  static const std::string rgbPrefix;

public:
  static std::string background(const unsigned int &color);
  static std::string foreground(const unsigned int &color);
  static std::string background(const unsigned int &red,
                                const unsigned int &green,
                                const unsigned int &blue);
  static std::string foreground(const unsigned int &red,
                                const unsigned int &green,
                                const unsigned int &blue);
};
} // namespace TE

#endif // COLOR_HPP
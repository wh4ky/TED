/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly
  appreciated.
  License is in the root of this project, please abide by it.
*/

#include <TermEngine/core.hpp>
#include <iostream>

int main() {
  TE::log::openLog();
  TE::log::openLog();

  for (int i; i < 1000; i++) { // Simulate abnormally heavy load.
    TE::log::toFile("Run number: " + std::to_string(i));
  }

  TE::log::closeLog();
  TE::log::closeLog();
}
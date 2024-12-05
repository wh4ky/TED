#include "classes.hpp"
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

class Sword : public Item {
public:
  Sword() {
    this->info.equipped = true;
    this->info.name = "sword";
    this->info.dealDamageRange.lowerBound = 10;
    this->info.dealDamageRange.upperBound = 15;
    this->info.selfBlockRange.lowerBound = 0.1;
    this->info.selfBlockRange.upperBound = 0.2;
  };
};

class Player : public Entity {
public:
  Player() {
    this->info.name = "PlayerOne";
    this->info.baseHealth = 100;
    this->info.currHealth = 100;
    this->info.weapon = std::make_unique<Sword>();
  }
};

class Goblin : public Entity {
public:
  Goblin() {
    this->info.name = "PlayerTwo";
    this->info.baseHealth = 100;
    this->info.currHealth = 100;
    this->info.weapon = std::make_unique<Sword>();
  }
};

int main() {
  std::unique_ptr<Entity> player = std::make_unique<Player>();
  std::unique_ptr<Entity> goblin = std::make_unique<Goblin>();

  std::cout << "! A WILD GOBLIN APPEARED !" << std::endl;

  while (true) {
    std::string option;
    bool valid_option = false;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    while (!valid_option) {
      std::cout << std::endl
                << "What do you do?" << std::endl
                << "Attack" << std::endl
                << "Exit" << std::endl
                << "- ";
      std::getline(std::cin, option);
      if (option == "Attack" || option == "attack") {
        Event::attack(player, goblin);
        valid_option = true;
      } else if (option == "Exit" || option == "exit") {
        std::cout << "Pussy, you fled.";
        return 0;
      } else if (option == "fKill") {
        goblin->editHealth(-10000);
        valid_option = true;
      } else {
        std::cout << "Not a valid option! Try again." << std::endl;
      }
    }

    if (goblin->info.currHealth <= 0) {
      std::cout << "The goblin has 0HP, You won!" << std::endl;
      break;
    } else {
      std::cout << "The goblin has " << goblin->info.currHealth << "HP."
                << std::endl;
    }
  }
  return 0;
}

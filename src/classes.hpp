#pragma once

#include <iostream>
#include <memory>
#include <random>
#include <string>

class RandomGens {
public:
  int getRandomWithinBounds(int lowerBound, int upperBound) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(lowerBound, upperBound);
    return dis(gen);
  }

  double getRandomWithinBounds(double lowerBound, double upperBound) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(lowerBound, upperBound);
    return dis(gen);
  }
};

class Item {
protected:
  RandomGens randgen;

public:
  struct Info {
    bool equipped;
    std::string name;
    struct SelfDamageRange {
      int lowerBound;
      int upperBound;
    } selfDamageRange; // Deal damage to owner
    struct DealDamageRange {
      int lowerBound;
      int upperBound;
    } dealDamageRange; // Deal damage to enemy
    int selfHealth;    // Heal owner
    int dealHealth;    // Heal enemy
    struct SelfBlockRange {
      double lowerBound;
      double upperBound;
    } selfBlockRange; // Give owner block
    struct DealBlockRange {
      double lowerBound;
      double upperBound;
    } dealBlockRange; // Give enemy block
  } info;

  inline virtual int getDealDamage() {
    return this->randgen.getRandomWithinBounds(
        this->info.dealDamageRange.lowerBound,
        this->info.dealDamageRange.upperBound);
  }

  inline virtual int getSelfDamage() {
    return this->randgen.getRandomWithinBounds(
        this->info.selfDamageRange.lowerBound,
        this->info.selfDamageRange.upperBound);
  }

  inline virtual double getDealBlock() {
    return this->randgen.getRandomWithinBounds(
        this->info.dealBlockRange.lowerBound,
        this->info.dealBlockRange.upperBound);
  }

  inline virtual double getSelfBlock() {
    return this->randgen.getRandomWithinBounds(
        this->info.selfBlockRange.lowerBound,
        this->info.selfBlockRange.upperBound);
  }
};

class Entity {
public:
  class Info {
  public:
    std::string name;
    int baseHealth;
    int currHealth;
    int baseDamage;
    double baseBlock;
    std::vector<std::unique_ptr<Item>> inventory;
    std::unique_ptr<Item> weapon;
    std::unique_ptr<Item> shield;
  } info;

  virtual void editHealth(const signed int &add) {
    this->info.currHealth += add;
  };
  virtual ~Entity() = default;
};

class Event { // TODO: adding events
public:
  static void attack(std::unique_ptr<Entity> const &attacker,
                     std::unique_ptr<Entity> const &enemy) {
    int damage = attacker->info.weapon->getDealDamage();
    double block = enemy->info.weapon->getSelfBlock() + enemy->info.baseBlock;
    enemy->editHealth(
        -std::max(static_cast<int>(damage - (damage * block)), 0));
  }
};
#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <map>

using namespace std;

struct HotDrink {
  virtual void prepare(float volume) = 0;
};

struct Coffee : HotDrink {
  void prepare(float volume) override {
    cout << "Grind some beans, boil water, pour " << volume << "ml" << endl;
  }
};

struct Tea : HotDrink {
  void prepare(float volume) override {
    cout << "Take a tea bag, boil water, pour "<< volume << "ml" << endl;
  }
};

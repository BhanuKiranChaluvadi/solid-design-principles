#pragma once
#include <string>
#include <map>

#include "HotDrinkFactory.h"
#include "CoffeeFactory.h"
#include "TeaFactory.h"

class DrinkFactory
{
  map<string, unique_ptr<HotDrinkFactory>> factories;

public:
  DrinkFactory(){
    factories["coffee"] = make_unique<CoffeeFactory> ();
    factories["tea"] = make_unique<TeaFactory> ();
  }

  unique_ptr<HotDrink> make_drink(const string& name) {
    auto drink = factories[name]->make();
    drink->prepare(100);
    return drink;
  }
};


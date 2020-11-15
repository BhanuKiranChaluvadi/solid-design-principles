# pragma once
#include "HotDrink.h"
#include "HotDrinkFactory.h"

struct HotDrinkFactory;

struct CoffeeFactory : HotDrinkFactory
{
  unique_ptr<HotDrink> make() override {
    return make_unique<Coffee>();  
  }
};

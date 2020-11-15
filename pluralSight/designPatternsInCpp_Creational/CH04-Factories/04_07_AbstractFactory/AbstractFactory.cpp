#include <iostream>
#include "HotDrink.h"
#include "DrinkFactory.h"

/* This might look ugly if we add more types
 * Many nested loops.
 */
unique_ptr<HotDrink> make_drink(string type) {
  unique_ptr<HotDrink> drink;
  if (type == "coffee")  {
    drink = std::make_unique<Coffee>();
    drink->prepare(100);
  }
  else if (type == "Tea") {
    drink = std::make_unique<Tea>();
    drink->prepare(100);
  }
  return drink;
}

int main() {
  
  // old way - no factories
  unique_ptr<HotDrink> d = make_drink("Tea");
  
  // using factories 
  DrinkFactory df;
  df.make_drink("coffee");

  return 0;
}
#include <iostream>
#include <string.h>

using namespace std;

class Entree {
protected:
  char _entree[10];
public:
  const char* getEntree() {
    return _entree;
  }
};

class Side {
protected:
  char _side[10];
public:
  const char* getSide() {
    return _side;
  }
};

class Drink {
protected:
  char _drink[10];
public:
  Drink() {
    cout << "\n Fill cup with soda" << endl;
    strcpy(_drink, "soda");
  }
  const char* getDrink() {
    return _drink;
  }
};

class ComboMeal {
private:
  Entree* entree;
  Side* side;
  Drink* drink;
  char _bag[100];
public:
  ComboMeal(const char *type){
    sprintf(_bag, "\n %s meal combo:", type);
  }
  void setEntree(Entree* e) {
    entree = e;
  }
  void setSide(Side* s) {
    side = s;
  }
  void setDrink(Drink* d) {
    drink = d;
  }
  const char* openMealBag() {
    sprintf(_bag, "%s %s, %s, %s ", _bag, entree->getEntree(), side->getSide(), drink->getDrink() );
    return _bag;
  }
};

int main()
{
  ComboMeal burger("Burger");
  cout << burger.openMealBag() << endl;  // entree/side/drink not initialized
  return 0;
}



#include <iostream>
#include <string.h>

using namespace std;

class Entree {
protected:
  char _entree[10];
public:
  Entree(){}
  const char* getEntree() {
    return _entree;
  }
};

class Burger : public Entree {
public:
  Burger() : Entree() {
    cout << "\n Grill burger patty, add tomatoes and place them in a bun";
    strcpy(_entree, "vegburger");
  }
};

class HotDog : public Entree {
public:
  HotDog() : Entree() {
    cout << "\n Cook sausage and place it in a bun";
    strcpy(_entree, "hotdog");
  }
};

class Side {
protected:
  char _side[10];
public:
  Side() {}
  const char* getSide() {
    return _side;
  } 
};

class Fries : public  Side {
public:
  Fries() : Side() {
    cout << "\n Fry and season potatoes";
    strcpy(_side, "fries");
  }
};

class Salad : public  Side {
public:
  Salad() : Side() {
    cout << "\n Toss green and dressing together";
    strcpy(_side, "salad");
  }
};

class Drink {
protected:
  char _drink[10];
public:
  Drink() {
    cout << "\n Fill cup with soda";
    strcpy(_drink, "soda");
  }
  const char* getDrink() {
    return _drink;
  } 
};

class MealCombo {
private:
  Entree* _entree;
  Side* _side;
  Drink* _drink;
  char _bag[100];
public:
  MealCombo(const char* type) {
    sprintf(_bag, "\n meal combo: %s", type);
  }
  void setEntree(Entree* e) {
    _entree = e;
  }
  void setSide(Side* s) {
    _side = s;
  }
  void setDrink(Drink* d) {
    _drink = d;
  }
  const char* openMealBag() {
    sprintf(_bag, "%s %s, %s, %s ", _bag, _entree->getEntree(), _side->getSide(), _drink->getDrink() );
    return _bag;
  }
};

class MealBuilder {
protected:
  MealCombo* _meal;
public:
  virtual void cookEntree()=0;
  virtual void cookSide()=0;
  virtual void fillDrink()=0;
  MealCombo* getMeal() {
    return _meal;
  }
};

class BurgerMeal : public MealBuilder {
public:
  BurgerMeal() {
    _meal = new MealCombo("Burger");
  }
  void cookEntree() {
    Burger* burger = new Burger();
    _meal->setEntree(burger);
  }
  void cookSide() {
    _meal->setSide(new Fries());
  }
  void fillDrink() {
    _meal->setDrink(new Drink());
  }
};

class HotDogMeal : public MealBuilder {
public:
  HotDogMeal() {
    _meal = new MealCombo("HotDog");
  }
  void cookEntree() {
    _meal->setEntree(new HotDog());
  }
  void cookSide() {
    _meal->setSide(new Salad());
  }
  void fillDrink() {
    _meal->setDrink(new Drink());
  }
};

int main() {

  // prompt user for their meal choice
  MealBuilder* cook;
  MealCombo* meal;
  int choice; 

  cout << "Select a Meal type: " << endl;
  cout << "1: Burger"<< endl;
  cout << "2: HotDog" << endl;
  cout << "Select: "<< endl;
  cin >> choice;
  cout << endl;

  // Instantiate appropriate builder based on user input
  switch (choice)
  {
  case 1:
    cook = new BurgerMeal();
    break;
  case 2:
    cook = new HotDogMeal();
    break;
  default:
    cout << "Invalid selection" << endl;
    cook = NULL;
    break;
  }

  if (cook != NULL) {

    cout << "Making the selected meal" << endl;
    cook->cookEntree();
    cook->cookSide();
    cook->fillDrink();

    meal = cook->getMeal();

    cout << meal->openMealBag() << endl;
  }


  return 0;
}
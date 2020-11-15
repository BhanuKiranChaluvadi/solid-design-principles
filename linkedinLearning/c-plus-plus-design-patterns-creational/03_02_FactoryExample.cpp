#include<iostream>
#include <string.h>
#include <memory>

using namespace std;

class Coffee {
protected:
  char _type[15];
public:
  Coffee () {

  }
  char* getType() {
    return _type;
  }
};

class Espresso : public Coffee {
public:
  Espresso() : Coffee() {
    strcpy(_type, "Espresso");
    cout << endl << "Making a cup of espresso"<< endl;
    cout << "Grind and brew one scoop of espresso beans." << endl;
  }
};

class Cappuccino : public Coffee {
public:
  Cappuccino() : Coffee() {
    strcpy(_type, "Cappuccino");
    cout << endl << "Making a cup of cappuccino"<< endl;
    cout << "Grind and brew one scoop of espresso beans." << endl;
    cout << "Heat and foam milk." << endl;
  }
};

class CoffeeMakerFactory {
private:
  Coffee* _coffee;
public:
  Coffee* getCoffee() {
    int choice;

    cout << "Select type of coffee to make: " << endl;
    cout << "1. Espresso" << endl;
    cout << "2. Cappuccino" << endl;
    cout << "selection: " << endl;
    cin >> choice;

    switch(choice) {
      case 1:
        return new Espresso;
      case 2:
        return new Cappuccino;
      default:
        cout << "Invalid Selection" <<endl;
        return NULL;
    } 

  }
};

int main() {

  CoffeeMakerFactory CoffeeMachine;
  Coffee* cup;
  cup = CoffeeMachine.getCoffee();

  cout << endl << "You have asked for a(n)" << cup->getType() << endl;

  delete cup;
  
  return 0;
} 

#include<iostream>
#include <string.h>

using namespace std;

class Door {
public:
  Door() {}
  virtual void open() = 0;
};

class GasCarDoor : public Door {
public:
  GasCarDoor() : Door() {
    cout << "Making a door for a gas car. " << endl;
  }
  void open() override {
    cout << "click" << endl;
  }
};

class ElectricCarDoor : public Door {
public:
  ElectricCarDoor() : Door() {
    cout << "Making a door for a electric car. " << endl;
  }
  void open() override {
    cout << "shhhhh" << endl;
  }
};

class Engine {
protected:
  char _sound[15];
public:
  Engine(){}
  virtual void Run() = 0;
};

class GasCarEngine : public Engine {
public:
  GasCarEngine() : Engine() {
    strcpy(_sound, "vroom");
    cout << "Making a engine for a gas car. " << endl;
  }
  void Run() override {
    cout << _sound << endl;
  }
};

class ElectricCarEngine : public Engine {
public:
  ElectricCarEngine() : Engine() {
    strcpy(_sound, "SHHHHH");
    cout << "Making a engine for a electric car. " << endl;    
  }
  void Run() override {
    cout << _sound << endl;
  }
};

// Factories
class CarFactory {
public:
  virtual Door* BuildDoor()=0;
  virtual Engine* BuildEngine()=0;
};

class GasCar : public CarFactory {
public:
  Door* BuildDoor() {
    return new GasCarDoor;
  }
  Engine* BuildEngine() {
    return new GasCarEngine;
  }
};

class ElectricCar : public CarFactory {
public:
  Door* BuildDoor() {
    return new ElectricCarDoor;
  }
  Engine* BuildEngine() {
    return new ElectricCarEngine;
  }
};

int main() {

  CarFactory* CarPlant;
  int choice; 

  cout << "Select a car type: " << endl;
  cout << "1: Gasoline"<< endl;
  cout << "2: Electric" << endl;
  cout << "Select: "<< endl;
  cin >> choice;
  cout << endl;

  // Door & Car

  switch (choice)
  {
  case 1:
    CarPlant = new GasCar();
    break;
  case 2:
    CarPlant = new ElectricCar();
    break;
  default:
    cout << "Invalid selection" << endl;
    CarPlant = NULL;
    break;
  }

  if (CarPlant != NULL) {
    Door* myDoor = CarPlant->BuildDoor();
    Engine* myEngine = CarPlant->BuildEngine();

    // Let's take it for a drive.
    myDoor->open();
    myEngine->Run();
  }
  return 0; 
}
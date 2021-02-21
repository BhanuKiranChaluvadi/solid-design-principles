


class Duck {
 public:
  virtual void quack();
  virtual void fly();
};

class MallardDuck : public Duck {
public:
  MallardDuck() {}
  void quack() override {}
  void fly() override {}
};

class Turkey {
 public:
  virtual void gooble();
  virtual void fly();
};

class WildTurkey : public Turkey {
 public:
  WildTurkey () {}
  void gooble() override {}
  void fly() override {};
};

class TurkeyAdapter : public Duck {
public:
  TurkeyAdapter(Turkey turkey) :turkey_(turkey) {}
  void quack() override {
    turkey_.gooble();
  }
  void fly() override {
    for (short int i=0; i<5; ++i){
      turkey_.fly();  // assume turcky fly slower
    }
  }
 private:
  Turkey turkey_;
};


// Client code
class DuckSimulator {
 public:
  DuckSimulator() {
    // test a duck
    Duck duck = MallardDuck();
    testDuck(duck);

    // test a turkey
    Turkey turkey = WildTurkey();
    Duck turkeyAdapter = TurkeyAdapter(turkey);
    testDuck(turkeyAdapter);

  }
  void testDuck(Duck duck) {
    duck.quack();
    duck.fly();
  }
};


int main() {
  return 0;
}
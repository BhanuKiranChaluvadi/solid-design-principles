#include <iostream>
#include <string>

using namespace std;

struct Person {
  string name;

  struct PersonImpl;
  PersonImpl* impl;

  Person();
  ~Person();

  void greet();
};

struct Person::PersonImpl {
  void greet(Person* p);
};

Person::Person() : impl(new PersonImpl) {}
Person::~Person() {delete impl;}

void Person::greet() {
  impl->greet(this);
}

void Person::PersonImpl::greet(Person* p) {
    printf("Hi, Greetings from %s \n", p->name.c_str());
}
int main() {

  Person p;
  p.name = "BhanuKiran";
  p.greet();
  return 0;
}
#pragma once
#include <string>
#include <iostream>

using namespace std; 

class PersonBuilder;

class Person
{
  // address
  std::string street_address, post_code, city;

  // employment
  std::string company_name, position;
  int annual_income = 0;

  Person() {}
public:
  static PersonBuilder create();

  Person(Person&& other)
    : street_address{move(other.street_address)},
      post_code{move(other.post_code)},
      city{move(other.city)},
      company_name{move(other.company_name)},
      position{move(other.position)},
      annual_income{other.annual_income}
  {
  }

  Person& operator=(Person&& other)
  {
    if (this == &other)
      return *this;
    street_address = move(other.street_address);
    post_code = move(other.post_code);
    city = move(other.city);
    company_name = move(other.company_name);
    position = move(other.position);
    annual_income = other.annual_income;
    return *this;
  }

  friend ostream &operator<< (ostream& os, const Person& p) {
      os
          << "street_address: " << p.street_address 
          << "post_code> " << p.post_code
          << "city" << p.city
          << "company_name" << p.company_name
          << "position" << p.position
          << "annual_income" << p.annual_income;
      return os;
  }

  friend class PersonBuilder;
  friend class PersonAddressBuilder;
  friend class PersonJobBuilder;
};

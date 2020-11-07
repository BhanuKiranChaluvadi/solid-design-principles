#pragma once
#include <string>

class PersonAddressBuilder : public PersonBuilder
{
  typedef PersonAddressBuilder Self;
public:
  explicit PersonAddressBuilder(Person& person)
    : PersonBuilder{ person }
  {
  }

  Self& at(const std::string street_address)
  {
    person.street_address = street_address;
    return *this;
  }

  Self& with_postcode(const std::string post_code)
  {
    person.post_code = post_code;
    return *this;
  }

  Self& in(const std::string city)
  {
    person.city = city;
    return *this;
  }
};
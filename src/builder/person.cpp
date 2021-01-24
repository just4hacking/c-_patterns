#include "./person.hpp"
#include "./person_builder.hpp"

PersonBuilder Person::create() {
  return PersonBuilder{};
}

Person::Person(Person&& other) : street_address{move(other.street_address)},
  post_code{move(other.post_code)},
  city{move(other.city)},
  company_name{move(other.company_name)},
  position{move(other.position)},
  annual_income{other.annual_income}
{}

Person& Person::operator=(Person&& other)
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

Person::~Person()
{
  std::cout << "Person destroyed\n";
}

Person::Person()
{
  std::cout << "Person created\n";
}

std::ostream& operator<<(std::ostream& os, const Person& obj)
{
  return os
    << "street_address: " << obj.street_address
    << " post_code: " << obj.post_code
    << " city: " << obj.city
    << " company_name: " << obj.company_name
    << " position: " << obj.position
    << " annual_income: " << obj.annual_income;
}
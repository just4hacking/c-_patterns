#pragma once
#include <string>
#include <iostream>

class PersonBuilder;

class Person
{
  // address
  std::string street_address, post_code, city;

  // employment
  std::string company_name, position;
  int annual_income = 0;

  Person();
  
public:
  ~Person();

  static PersonBuilder create();

  Person(Person&& other);

  Person& operator=(Person&& other);

  friend std::ostream& operator<<(std::ostream& os, const Person& obj);

  friend class PersonBuilder;
  friend class PersonAddressBuilder;
  friend class PersonJobBuilder;
};

/* EXAMPLE
int main(int argc, char *argv[]) {

  Person p = Person::create()
    .lives()
      .at("123 London Road")
      .with_postcode("SW1 1GB")
      .in("London")
    .works()
      .at("Pragmasoft")
      .as_a("Consultant")
      .earning(10e6);
      
  cout << p << endl;
  return 0;
}
*/

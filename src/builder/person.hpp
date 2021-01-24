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

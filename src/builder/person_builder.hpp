#pragma once
#include "./person.hpp"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
protected:
  Person& person;
  explicit PersonBuilderBase(Person& person);

public:
  operator Person() const;

  // builder facets

  PersonAddressBuilder lives() const;
  PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
  Person p;
public:
  PersonBuilder();

};
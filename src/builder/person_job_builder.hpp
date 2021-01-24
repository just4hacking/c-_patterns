#pragma once
#include <string>
#include "./person_builder.hpp"

class PersonJobBuilder : public PersonBuilderBase
{
  typedef PersonJobBuilder Self;
public:
  explicit PersonJobBuilder(Person& person);

  Self& at(std::string company_name);

  Self& as_a(std::string position);

  Self& earning(int annual_income);
};
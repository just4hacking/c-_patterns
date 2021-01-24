#pragma once
#include <string>
#include "./person_builder.hpp"

class PersonAddressBuilder : public PersonBuilderBase
{
  typedef PersonAddressBuilder Self;
public:
  explicit PersonAddressBuilder(Person& person);

  Self& at(std::string street_address);

  Self& with_postcode(std::string post_code);

  Self& in(std::string city);
};
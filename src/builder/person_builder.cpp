#include "./person_builder.hpp"
#include "./person_address_builder.hpp"
#include "./person_job_builder.hpp"

PersonBuilderBase::PersonBuilderBase(Person& person) : person(person) {

}

PersonBuilder::PersonBuilder() : PersonBuilderBase(p) {

}

PersonAddressBuilder PersonBuilderBase::lives() const {
  return PersonAddressBuilder{ person };
}

PersonJobBuilder PersonBuilderBase::works() const {
  return PersonJobBuilder{ person };
}

PersonBuilderBase::operator Person() const
{
  return std::move(person);
}
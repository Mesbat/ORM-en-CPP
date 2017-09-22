// PROJECT OwlORM, Etna 2017, Mesbat_y & Abbass_S //
// ---------------------------------------------- //

#include "../headers/Field.hpp"
using namespace ORM;

Field&	Field::operator=(std::string value)
{
  this->_value = value;
  return  (*this);
}

std::string Field::getValue() const
{
  return (this->_value);
}

void Field::setValue(std::string value) {
  this->_value = value;
}

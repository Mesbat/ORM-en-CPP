// PROJECT OwlORM, Etna 2017, Mesbat_y & Abbass_S //
// ---------------------------------------------- //

#include "../headers/Table.hpp"
using namespace ORM;

Table::Table(std::string tableName, std::string keyName) : _NameTable(tableName), _PrimaryKey(keyName)
{

}

bool  Table::addField(std::string fieldName, Field &field)
{
  this->_Fields.emplace(fieldName, field);
  return (true);
}

std::string Table::getTableName()
{
  return (this->_NameTable);
}

std::string Table::getKeyName()
{
  return (this->_PrimaryKey);
}

std::unordered_map<std::string, Field&> Table::getFields()
{
  return (this->_Fields);
}

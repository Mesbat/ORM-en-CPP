// PROJECT OwlORM, Etna 2017, Mesbat_y & Abbass_S //
// ---------------------------------------------- //

#include "../headers/DB.hpp"
using namespace ORM;

DB DB::m_instance=DB();

DB& DB::Instance()
{
    return m_instance;
}

bool  DB::connect(std::string Address, std::string Username, std::string Password) {
  sql::Driver *driver;
  sql::Statement *stmt;
  sql::Connection *con;

  driver = get_driver_instance();
  con = driver->connect(Address, Username, Password);

  /* Création et/ou Selection de la BDD */
  stmt = con->createStatement();
  stmt->execute("CREATE DATABASE IF NOT EXISTS OwlORM;");

  con->setSchema("OwlORM");
  this->_Con = con;
  return (true);
}

void DB::save(Table& Table) {
  sql::Statement *stmt;
  std::unordered_map<std::string, Field&> Fields;
  Fields = Table.getFields();
  bool first_value = true;
  stmt = this->_Con->createStatement();

  std::string sql = "CREATE TABLE IF NOT EXISTS "+ Table.getTableName() +" " +
                   "("+ Table.getKeyName() +" INTEGER not NULL AUTO_INCREMENT,";
  for (auto const& x : Fields)
  {
    if (x.first != Table.getKeyName())
      sql += " " + x.first + " VARCHAR(255),";
  }
  sql += " PRIMARY KEY ( "+ Table.getKeyName() +" ))";
  stmt->execute(sql);
  sql = "REPLACE INTO " + Table.getTableName() + " (";
  for (auto const& i : Fields)
  {
    if (!first_value)
      sql += ", " + i.first;
    else {
      sql += i.first;
      first_value = false;
    }
  }
  sql += ") VALUES (";
  first_value = true;
  for (auto const& a : Fields)
  {
    if (!first_value) {
      if (a.second.getValue().empty())
        sql += ", NULL";
      else
        sql += ", '" + a.second.getValue() + "'";
    } else {
      if (a.second.getValue().empty())
        sql += "NULL";
      else
        sql += "'" + a.second.getValue() + "'";
      first_value = false;
    }

  }
  sql += ");";
  stmt->execute(sql);
  sql::ResultSet *res = stmt->executeQuery("SELECT LAST_INSERT_ID() AS id;");
  res->next();
  for (auto const& z : Fields)
  {
    if (z.first == Table.getKeyName())
      z.second = std::to_string(res->getInt64("id"));
  }
}

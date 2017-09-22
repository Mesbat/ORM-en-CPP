// PROJECT OwlORM, Etna 2017, Mesbat_y & Abbass_S //
// ---------------------------------------------- //

#ifndef _DB_HPP_
#define _DB_HPP_

#include "Table.hpp"

/* Standard C++ includes */
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <memory>

/* C++ MysqlConnector */
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

namespace ORM {
  class DB {
  private:
    sql::Connection *_Con;
    static DB& Instance();
  public:
    static DB m_instance;
    bool  connect(std::string, std::string, std::string);
    void  save(Table&);

    template<class T>
    std::vector<T> selectAll()
    {
      std::vector<T> Data;
      T clone;
      sql::Statement *stmt;
      stmt = this->_Con->createStatement();
      std::unordered_map<std::string, Field&> Fields;
      sql::ResultSet *res = stmt->executeQuery("SELECT * FROM " + clone.getTableName() + ";");

      Fields = clone.getFields();

      while (res->next()) {
        for (auto const& z : Fields)
        {
          if (z.first == clone.getKeyName())
            z.second = res->getString(clone.getKeyName());
          else
            z.second = res->getString("username");
        }
        Data.push_back (clone);
      }

      return (Data);
    }

    template<class T>
    T findById(int id)
    {
      T clone;
      sql::Statement *stmt;
      stmt = this->_Con->createStatement();
      std::unordered_map<std::string, Field&> Fields;
      sql::ResultSet *res = stmt->executeQuery("SELECT * FROM " + clone.getTableName() + " WHERE " + clone.getKeyName() + "=" + std::to_string(id) + ";");

      Fields = clone.getFields();

      while (res->next()) {
        for (auto const& z : Fields)
        {
          if (z.first == clone.getKeyName())
            z.second = res->getString(clone.getKeyName());
          else
            z.second = res->getString("username");
        }
      }

      return (clone);
    }
  };
} /*ORM */

#endif

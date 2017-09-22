// PROJECT OwlORM, Etna 2017, Mesbat_y & Abbass_S //
// ---------------------------------------------- //

#ifndef _TABLE_HPP_
#define _TABLE_HPP_

#include "Field.hpp"

/* Standard C++ includes */
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stdlib.h>
#include <memory>

namespace ORM {
  class Table {
  private:
    std::unordered_map<std::string, Field&> _Fields;
    std::string _NameTable;
    std::string _PrimaryKey;
  public:
    Table(std::string, std::string);
    bool  addField(std::string, Field&);
    std::unordered_map<std::string, Field&> getFields();
    std::string getTableName();
    std::string getKeyName();
  };
} /*ORM */

#endif

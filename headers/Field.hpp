// PROJECT OwlORM, Etna 2017, Mesbat_y & Abbass_S //
// ---------------------------------------------- //

#ifndef _FIELD_HPP_
#define _FIELD_HPP_

/* Standard C++ includes */
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <stdlib.h>
#include <memory>

namespace ORM {
  class Field {
  private:
    /* data */
    std::string _value;
  public:
    operator int() { return atoi(this->_value.c_str()); }
    operator std::string() { return this->_value; }
    std::string getValue() const;
    void        setValue(std::string);
    Field	&operator=(std::string);
  };
} /*ORM */

#endif

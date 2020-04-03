// Dennis Pham
// T353F647
// August 8 2018

#ifndef NOVEL_HPP
#define NOVEL_HPP

#include "Book.hpp"
#include <iostream>

class Novel : public Book
{
public:
    Novel(): Book() {};
    Novel(const std::string& l,
          const std::string& f,
          const std::string& t,
          const int& p);
    virtual ~Novel() {};
 
    // friend const bool operator ==(const Novel& left, const Novel& right);
    // friend const bool operator !=(const Novel& left, const Novel& right) {return  !(left == right); };
    // friend const bool operator <(const Novel& left, const Novel& right);
    // friend const bool operator >=(const Novel& left, const Novel& right) {return left > right || left == right; };
    // friend const bool operator >(const Novel& left, const Novel& right);
    // friend const bool operator <=(const Novel& left, const Novel& right) {return left < right || left == right; };
    
    virtual void print() override;
};

#endif

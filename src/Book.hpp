// Dennis Pham
// T353F647
// August 8 2018

#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book
{
public:
    virtual ~Book() {};

    const std::string author() const { return std::string(first + ' ' + last); };  
    const std::string title() const { return _title; }; 
    const int year() const { return published; };

    void setLast(const std::string& name) { last = name; };
    void setFirst(const std::string& name) { first = name; };
    void setTitle(const std::string& name) { _title = name; };
    void setPub(const int& year) { published = year; };

    
    friend bool operator ==(const Book& left, const Book& right);
    friend bool operator !=(const Book& left, const Book& right) {return  !(left == right); };
    friend bool operator <(const Book& left, const Book& right);
    friend bool operator >=(const Book& left, const Book& right) {return left > right || left == right; };
    friend bool operator >(const Book& left, const Book& right);
    friend bool operator <=(const Book& left, const Book& right) {return left < right || left == right; };
   
    virtual void print() = 0;
protected:
    Book();
    Book(const std::string& l, 
         const std::string& f,
         const std::string& t,
         const int& p);

protected:
    std::string last, first, _title;
    int published;
private:
};

#endif

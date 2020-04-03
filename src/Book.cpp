// Dennis Pham
// T353F647
// August 8 2018

#include "Book.hpp"

Book::Book():
    last(std::string()),
    first(std::string()),
    _title(std::string()),
    published(int())
{}

Book::Book(const std::string& l,
           const std::string& f,
           const std::string& t,
           const int& p):
    last(l),
    first(f),
    _title(t),
    published(p)
{}

bool operator ==(const Book& left, const Book& right)
{
    if(left.last + " "  + left.first != right.last + " " + right.last)
        return false;
    else
    {
        if(left.title() != right.title())
            return false;
    }
    return true;
}

bool operator <(const Book& left, const Book& right)
{
    if(left.last + " " + left.first == right.last + " " + right.first)
    {
        if(left.title() >= right.title())
            return false;
    }

    if(left.last + " " + left.first >= right.last + " " + right.first)
        return false;

    return true;
}

bool operator >(const Book& left, const Book& right)
{
    if(left.last + " " + left.first == right.last + " " + right.first)
    {
        if(left.title() <= right.title())
            return false;
    }

    if(left.last + " " + left.first <= right.last + " " + right.first)
        return false;
    return true;
}

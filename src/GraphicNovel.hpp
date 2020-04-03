// Dennis Pham
// T353F647
// August 8 2018

#ifndef GRAPHIC_NOVEL_HPP
#define GRAPHIC_NOVEL_HPP

#include "Book.hpp"
#include <iostream>

class GraphicNovel : public Book
{
public:
    // Constructors
    GraphicNovel(): Book() {};
    GraphicNovel(const std::string& l,
                 const std::string& f,
                 const std::string& a,
                 const std::string& t,
                 const int& p);
    virtual ~GraphicNovel() {};

    // Accessors
    const std::string returnArtist() { return illustrator; };

    // Mutators
    void setArtist(const std::string& name) { illustrator = name; };

    // friend const bool operator ==(const GraphicNovel& left, const GraphicNovel& right);
    // friend const bool operator !=(const GraphicNovel& left, const GraphicNovel& right) { return !(left == right); };
    // friend const bool operator <(const GraphicNovel& left, const GraphicNovel& right);
    // friend const bool operator <=(const GraphicNovel& left, const GraphicNovel& right) { return (left < right) || (left == right); };
    // friend const bool operator >(const GraphicNovel& left, const GraphicNovel& right);
    // friend const bool operator >=(const GraphicNovel& left, const GraphicNovel& right) { return (left > right) || (left == right); };

    virtual void print() override;

private:
    std::string illustrator;
};

#endif

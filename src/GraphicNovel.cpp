// Dennis Pham
// T353F647
// August 8 2018

#include "GraphicNovel.hpp"

GraphicNovel::GraphicNovel(const std::string& l,
                           const std::string& f,
                           const std::string& a,
                           const std::string& t,
                           const int& p):
    Book(l, f, t, p),
    illustrator(a)
{}

// const bool operator ==(const GraphicNovel& left, const GraphicNovel& right)
// {
//     if(left.author() != right.author())
//         return false;
//     else
//     {
//         if(left.title() != right.title())
//             return false;
//     }
//     return true;
// }

// const bool operator <(const GraphicNovel& left, const GraphicNovel& right)
// {
//     std::cout << "comparing " << left.title() << " with " << right.title() << std::endl;

//     if(left.author() == right.author())
//     {
//         if(left.title() >= right.title())
//             return false;
//     }

//     if(left.author() >= right.author())
//         return false;

//     return true;
// }

// const bool operator >(const GraphicNovel& left, const GraphicNovel& right)
// {
//     std::cout << "comparing " << left.title() << " with " << right.title() << std::endl;

//     if(left.author() == right.author())
//     {
//         if(left.title() >= right.title())
//             return false;
//     }

//     if(left.author() <= right.author())
//         return false;
//     return true;
// }


void GraphicNovel::print()
{
    std::cout << "Graphic Novel\nAuthor: "
              << author()
              << "\nTitle: " << title()
              << "\nIllustrator: " << illustrator
              << "\nPublished: " << published << std::endl;
}



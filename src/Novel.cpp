// Dennis Pham
// T353F647
// August 8 2018

#include "Novel.hpp"
#include <iostream>

Novel::Novel(const std::string& l,
             const std::string& f,
             const std::string& t,
             const int& p):Book(l, f, t, p)
{}

// const bool operator ==(const Novel& left, const Novel& right)
// {
//     if(left.author() != right.author())
//         return false;
//     if(left.title() != right.author())
//         return false;
//     if(left.published != right.published)
//         return false;
//     return true;
// }

// const bool operator <(const Novel& left, const Novel& right)
// {
//     if(left.author() == right.author())
//     {
//         if(left.title() >= right.title())
//             return false;
//     }
    
//     if(left.author() >= right.author())
//         return false;
//     return true;
// }



// const bool operator >(const Novel& left, const Novel& right)
// {
//     if(left.author() == right.author())
//     {
//         if(left.title() <= right.title())
//             return false;
//     }
    
//     if(left.author() <= right.author())
//         return false;
//     return true;
// }
    





void Novel::print()
{
    std::cout << "Novel\nAuthor: "
              << first << ' ' << last
              << "\nTitle: " << _title
              << "\nPublished: " << published << std::endl;
}

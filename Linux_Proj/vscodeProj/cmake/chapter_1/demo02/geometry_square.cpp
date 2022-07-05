#include "geometry_square.hpp"
#include <cmath>
namespace geometry{
    namespace area{
        template <class T>
        T square(T len)
        {
            return std::pow(len,2);
        }
        
        double square(double len)
        {
            return std::pow(len,2); 
        }
    }
}
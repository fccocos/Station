#include "geometry_polygon.hpp"
#include <cmath>

namespace geometry{
    namespace area{
        template <class T>
        T polygon(int nSides, T side)
        {
            T perimeter = nSides*side;
            T apothem = side/((std::tan(M_PI/nSides))*2);
            return (perimeter*apothem)/2;
        }
        double polygon(int nSides, double side)
        {
            double perimeter = nSides*side;
            double apothem = side/((std::tan(M_PI/nSides))*2);
            return (perimeter*apothem)/2;
        }
    }
}
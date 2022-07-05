#include "geometry_rhombus.hpp"
#include <cmath>

namespace geometry{
    namespace area{
        template<typename T>
        T rhombus(T prinDiag, T secDiag)
        {
            return (prinDiag*secDiag)/2;
        }
        double rhombus(double prinDiag, double secDiag )
        {
            return (prinDiag*secDiag)/2;
        }
    }
}
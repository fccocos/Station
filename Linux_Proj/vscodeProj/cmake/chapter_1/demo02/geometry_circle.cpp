#include "geometry_circle.hpp"
#include <cmath>

namespace geometry{
    namespace area{
        template <class T>
        T circle(T radius)
        {
            return (M_PI*std::pow(radius,2));
        }
        double circle(double radius)
        {
            return (M_PI*std::pow(radius,2));
        }
    }
}
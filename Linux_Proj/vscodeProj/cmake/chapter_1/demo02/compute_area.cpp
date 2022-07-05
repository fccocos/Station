#include "geometry_circle.hpp"
#include "geometry_polygon.hpp"
#include "geometry_rhombus.hpp"
#include "geometry_square.hpp"

#include <cstdlib>
#include <iostream>

int main()
{
    using namespace geometry;
    double radius  = 2.5293;
    double A_circle = area::circle(radius);
    std::cout<<"A_circle of radius "<<radius<<" has an area of "<<
    A_circle<<std::endl;

    int nSides = 10;
    double side = 1.29312;
    double A_polygon = area::polygon(nSides,side);
    std::cout<<"A regular ploygon of "<<nSides<<" sides of length "<<side
        <<" has an area of "<<A_polygon<<std::endl;
    
    double prinDiag = 7.8912;
    double secDiag = 5.0;
    double A_rhombus = area::rhombus(prinDiag, secDiag);
    std::cout<<"A rhombus of principal diagonal "<<prinDiag<<
        " and secondary diagonal "<< secDiag<<" has an area of "<< 
        A_rhombus<<std::endl;
    
    double len = 10.0;
    double A_square = area::square(len);
    std::cout<<"A square of side "<<len<<" has an area of "<<
        A_square<<std::endl;

    exit(EXIT_SUCCESS);
}
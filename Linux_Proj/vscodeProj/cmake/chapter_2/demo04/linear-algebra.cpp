#include <chrono>
#include <iostream>

#include "Eigen/Dense"

EIGEN_DONT_INLINE 
double simple_function(Eigen::VectorXd &va, Eigen::VectorXd &vb)
{
    double d= va.dot(vb);
    return d;
}

int main() 
{
    int len=1000000;
    int num_repetitions = 100;

    Eigen::VectorXd va = Eigen::VectorXd::Random(len);
    Eigen::VectorXd vb = Eigen::VectorXd::Random(len);

    double result;
    auto start = std::chrono::system_clock::now();
    for(auto i = 0; i < num_repetitions;i++)
    {
        result = simple_function(va, vb);
    }
    auto end = std::chrono::system_clock::now();
    auto elapsed_senconds = end-start;

    std::cout <<"result: "<<result<<std::endl;
    std::cout << "elapsed seconds: "<<elapsed_senconds.count()<<std::endl;
    
}
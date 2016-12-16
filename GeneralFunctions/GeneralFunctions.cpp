#include <cmath>
#include "GeneralFunctions.h"


std::vector<double> GeneralFunctions::nablaF(std::vector<double> x)
{
    std::vector<double> y;
    
    y.push_back(2*(x[0]));
    y.push_back(2*(x[1]-1));
    
    return y;
}

double GeneralFunctions::f(std::vector<double> x)
{
    return pow(x[0], 2) + pow(x[1]-1, 2);
}

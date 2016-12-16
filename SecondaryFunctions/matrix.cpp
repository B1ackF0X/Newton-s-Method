#include <iostream>
#include <Eigen/Dense>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


#define SIZE 2

using namespace Eigen;

std::vector<double> gesNablaF(std::vector<double> nablaF)
{
    int i;
    int n = nablaF.size();
    std::vector<double> p(n);
    
    Eigen::Matrix<double, SIZE, SIZE> gessian;
    Eigen::Matrix<double, SIZE, SIZE> m;
    Eigen::Matrix<double, SIZE, 1> vector;
    Eigen::Matrix<double, SIZE, 1> v;
    
    gessian << 2, 0,
               0, 2;
               
    m = gessian.inverse();
    
    for(i = 0; i < n; i++)
        vector(i, 0) = nablaF[i];
    
    v = m*vector;
    
    for(i = 0; i < n; i++)
        p[i] = v(i, 0);
    
    return p;
}

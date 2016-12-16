#include <iostream>
#include <stdio.h>
#include "NewtonsMethod/NewtonsMethod.h"


int main(void)
{
    int n = 2;
    std::vector<double> p(n);
    
    NewtonsMethod newtonsMethod;
    
    p = newtonsMethod.Compute(n, 0.0000001, 0.001);
    
    printf("function minimum is %lf, %lf\n", p[0], p[1]);
    
    return 0;
}

#include <stdio.h>
#include <cmath>
#include <vector>
#include "matrix.h"
#include "NewtonsMethod.h"
#include "TangentsMethod.h"


std::vector<double> NewtonsMethod::Compute(int n, double epsilon, double alpha_epsilon)
{
    return CompositeNewtonsMethod(n, epsilon, alpha_epsilon);
}

std::vector<double> NewtonsMethod::Substitution(
                                            std::vector<double> x,
                                            double alpha,
                                            std::vector<double> gesNablaF
                                            )
{
    return PartialNewtonsMethod(x, alpha, gesNablaF);
}

std::vector<double> NewtonsMethod::CompositeNewtonsMethod(int n, double epsilon, double alpha_epsilon)
{
    int i;
    double alpha;
    std::vector<double> x(n);
    std::vector<double> F1(n);
    TangentsMethod TangentsMethod;
    
    for(i = 0; i < n; i++)
        x[i] = 10.0;
    
    alpha = TangentsMethod.Compute(0.0, 1.0, x, gesNablaF(nablaF(x)), alpha_epsilon);
    
    F1 = PartialNewtonsMethod(x, alpha, gesNablaF(nablaF(x)));
    
    while(!StopCondition(x, F1, epsilon))
    {
        x = F1;
        alpha = TangentsMethod.Compute(0.0, 1.0, x, gesNablaF(nablaF(x)), alpha_epsilon);
        F1 = PartialNewtonsMethod(x, alpha, gesNablaF(nablaF(x)));
    }
    
    return F1;
}

std::vector<double> NewtonsMethod::PartialNewtonsMethod(
                                                    std::vector<double> x,
                                                    double alpha,
                                                    std::vector<double> gesNablaF
                                                    )
{
    int i;
    std::vector<double> p;
    
    for(i = 0; i < x.size(); i++)
        p.push_back(x[i] - alpha * gesNablaF[i]);
    
    return p;
}

int NewtonsMethod::StopCondition(
                                std::vector<double> F1, 
                                std::vector<double>F2,
                                double epsilon
                                )
{
    int i;
    
    for(i = 0; i < F1.size(); i++)
        if(!(fabs(F2[i] - F1[i]) < epsilon))
            return 0;
    
    return 1;
}

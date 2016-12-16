#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include "NewtonsMethod.h"
#include "TangentsMethod.h"


double TangentsMethod::Compute(
                            double a,
                            double b,
                            std::vector<double> x,
                            std::vector<double> gesNablaF,
                            double alpha_epsilon
                            )
{
    return CompositeTangentsMethod(a, b, x, gesNablaF, alpha_epsilon);
}

double TangentsMethod::CompositeTangentsMethod(
                                            double a,
                                            double b,
                                            std::vector<double> x,
                                            std::vector<double> gesNablaF,
                                            double alpha_epsilon
                                            )
{
    double c;
    
    
    if((FluxionForAlfa(x, a, gesNablaF)*FluxionForAlfa(x, b, gesNablaF)) > 0.0)
    {
        if(FluxionForAlfa(x, b, gesNablaF) < 0.0)
            return b;
            
        if(FluxionForAlfa(x, a, gesNablaF) > 0.0)
            return a;
    }
    
    c = PartialTangentsMethod(a, b, x, gesNablaF);
    
    while(!StopCondition(x, c, gesNablaF, alpha_epsilon))
    {
        if(FluxionForAlfa(x, c, gesNablaF) < -alpha_epsilon)
        {
            a = c;
        }
        else if(FluxionForAlfa(x, c, gesNablaF) > alpha_epsilon)
        {
            b = c;
        }
        else
        {
            return c;
        }
        
        c = PartialTangentsMethod(a, b, x, gesNablaF);
    }
    
    return c;
}

double TangentsMethod::PartialTangentsMethod(
                                        double a,
                                        double b,
                                        std::vector<double> x,
                                        std::vector<double> gesNablaF
                                        )
{
    double fa, fb;
    double fHatchA, fHatchB;
    
    fa = FunctionForAlfa(x, a, gesNablaF);
    fb = FunctionForAlfa(x, b, gesNablaF);
    
    fHatchA = FluxionForAlfa(x, a, gesNablaF);
    fHatchB = FluxionForAlfa(x, b, gesNablaF);
    
    return (fa - fb + fHatchB*b - fHatchA*a)/(fHatchB - fHatchA);
}

double TangentsMethod::FluxionForAlfa(
                                    std::vector<double> x,
                                    double c,
                                    std::vector<double> gesNablaF
                                    )
{
    double h = 0.000001;
    double fluxion;
    
    fluxion = (FunctionForAlfa(x, c + h, gesNablaF) -
                                FunctionForAlfa(x, c, gesNablaF))/h;
    
    return fluxion;
}

double TangentsMethod::FunctionForAlfa(
                                    std::vector<double> x,
                                    double c,
                                    std::vector<double> gesNablaF
                                    )
{
    NewtonsMethod NewtonsMethod;
    
    return f(NewtonsMethod.Substitution(x, c, gesNablaF));
}

double TangentsMethod::StopCondition(
                                std::vector<double> x,
                                double c,
                                std::vector<double> gesNablaF,
                                double alpha_epsilon
                                )
{
    if(fabs(FluxionForAlfa(x, c, gesNablaF)) < alpha_epsilon)
        return 1;
    
    return 0;
}

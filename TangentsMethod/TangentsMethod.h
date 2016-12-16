#include <vector>

class TangentsMethod : GeneralFunctions
{
    public:
            double Compute(
                            double a,
                            double b,
                            std::vector<double> x,
                            std::vector<double> gesNablaF,
                            double alpha_epsilon
                            );
    private:
            double CompositeTangentsMethod(
                            double a,
                            double b,
                            std::vector<double> x,
                            std::vector<double> gesNablaF, 
                            double alpha_epsilon
                            );
            double PartialTangentsMethod(
                            double a,
                            double b,
                            std::vector<double> x,
                            std::vector<double> gesNablaF
                            );
            double FluxionForAlfa(
                            std::vector<double> x,
                            double c,
                            std::vector<double> gesNablaF
                            );
            double FunctionForAlfa(
                            std::vector<double> x,
                            double c,
                            std::vector<double> gesNablaF
                            );
            double StopCondition(
                            std::vector<double> x,
                            double c,
                            std::vector<double> gesNablaF,
                            double alpha_epsilon
                            );
};

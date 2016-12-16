#include <vector>
#include "GeneralFunctions.h"

class NewtonsMethod : public GeneralFunctions
{
    public:
            std::vector<double> Compute(int n, double epsilon, double alpha_epsilon);
            std::vector<double> Substitution(
                                        std::vector<double> x,
                                        double alpha,
                                        std::vector<double> gesNablaF
                                        );
    
    private:
            std::vector<double> CompositeNewtonsMethod(int n, double epsilon, double alpha_epsilon);
            std::vector<double> PartialNewtonsMethod(
                                                std::vector<double> x,
                                                double alpha,
                                                std::vector<double> gesNablaF
                                                );
                            int StopCondition(
                                        std::vector<double> F1,
                                        std::vector<double> F2,
                                        double epsilon
                                        );
};

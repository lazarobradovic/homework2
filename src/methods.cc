#include "header.hh"

double ComputeArithmetic::compute(unsigned int N){
    double sol = 0;

    for (unsigned int k=1; k<=N; k++) {
        sol += k;
    }
    
    return sol;
}


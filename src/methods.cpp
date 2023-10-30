//
//  definitions.cpp
//  arthmeticseries
//
//  Created by Lazar Obradovic on 19.10.2023.
//

#include "methods.hpp"

using namespace std;

double Series::getAnalyticPrediction(){
    return nan(""); // Default returns NaN
}

double ComputeArithmetic::compute(unsigned int N){
    double sol = 0;

    for (unsigned int k=1; k<=N; k++) {
        sol += k;
    }
    
    return sol;
}

double ComputePi::compute(unsigned int N){
    double sol = 0.0;
    double sum = 0.0;

    for (unsigned int k=1; k<=N; k++) {
        sum += 1.0/(k * k);
    }
    
    sol = sqrt(6*sum);
    
    return sol;
}

double ComputePi::getAnalyticPrediction(){
    return M_PI; // Returns the value of Pi.
}

void PrintSeries::dump(){
    double output;
    
    for (unsigned int k=0; k<frequency.size()-1; k++) {
        if (frequency[k+1]-frequency[k]<maxiter) {
            output = frequency[k+1]-frequency[k];
            std::cout << "\nThe result is: " << output << std::endl;
        }
    }
    
}

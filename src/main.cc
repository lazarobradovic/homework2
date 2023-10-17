#include <iostream>
#include <numeric> //For accumulate operation
#include "header.hh"
using namespace std;
 
int main()
{
    // Initializing N and creating an objet with computeArithmetics
    unsigned int N = 10;
    ComputeArithmetic arithmeticSeries;
    double result = arithmeticSeries.compute(N);
 
    // Starting the summation from 0
    cout << "\nThe Arithmetic Series gives: " << result << std::endl;
 
    return 0;
}

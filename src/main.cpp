//
//  methods.cpp
//  arthmeticseries
//
//  Created by Lazar Obradovic on 19.10.2023.
//


#include "methods.cpp"

using namespace std;
 
int main()
{
    // Initializing N and creating an objet with computeArithmetics
    // Letting the
    unsigned int N;
    std::string choice;
    std::cout << "Enter 'A' for arithmetic series or 'P' for Pi series: ";
    std::cin >> choice;
    
    // Define new class of object depending on input
    Series* seriesPtr = nullptr;
    
    if (choice == "A") {
        seriesPtr = new ComputeArithmetic();
    }
    else if (choice == "P") {
        seriesPtr = new ComputePi();
    }
    else {
        std::cout << "Please enter a valid value (A or P).";
        return 1;
    }
    
    std::cout << "Enter the integer cutoff for the series: ";
    std::cin >> N;
    
    // This does not work as intended. Supposed to check whether N is an integer.
    if (N < 0) {
        std::cout << "You must enter a positive integer.\n";
        return 1;
    }
    
    double result = seriesPtr->compute(N);
 
    // Output the result of the Series
    cout << "\nThe Series result is: " << result << std::endl;
    
    
    // Defining Series, frequency and maxiter. Calling dump().
    
    /* For next time : frequency should be an integer. Then dump should compute ComputePi or ComputeArithmetic for frequency<maxiter. At least that is my last understanding. Or better ! Compute frequency = delta compute(n+1)-compute(n). If frequency<maxiter, stop. Frequency computes the step, and while the step is smaller than precision, we stop. This  */
    std::vector<double> frequency(5);
    
    frequency[0] = 5;    
    frequency[1] = 15;
    frequency[2] = 24;
    frequency[3] = 36;
    frequency[4] = 37;
    
    int maxiter = 10;
    ComputeArithmetic mySeries;
    PrintSeries printer(mySeries,frequency,maxiter);
    
    printer.dump();
    
    // std::cout << "Enter the integer cutoff for the series: ";
 
    return 0;
}

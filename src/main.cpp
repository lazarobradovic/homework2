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
    else
    {
        double result = seriesPtr->compute(N);
        cout << "\nThe Series result is: " << result << std::endl;
    }
    
    // Defining Series, frequency and maxiter. Calling dump().
    
    
    int frequency;
    std::cout << "Enter an integer value for the frequency: ";
    std::cin >> frequency;

    int maxiter;
    std::cout << "Enter an integer value for the maximum of iterations: ";
    std::cin >> maxiter;
    
    PrintSeries printer(*seriesPtr,frequency,maxiter);
    WriteSeries writer(*seriesPtr,frequency,maxiter);

    /*
    WRITING INTO A FILE
    */

    /* std::string separatorDecision;
    std::cout << "Enter the wanted separator for the output file (comma, space/tab or pipe): ";
    std::cin >> separatorDecision; */

    printer.dump();
    writer.dump(); // SOMETHING'S WRONG WITH IT.
 
    return 0;
}

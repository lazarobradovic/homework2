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
    unsigned int N = 0;

    while (N<maxiter)
    {
        output = series.compute(N); // Here series is supposed to correspond to seriesPtr in the main
        std::cout << "\nThe result is: " << output << std::endl;
        N += frequency;
    }
    
    std::cout << "\nThe series converges to: " << series.getAnalyticPrediction() << std::endl;
}

/*
The WriteSeries should write the results in a file.
*/

void WriteSeries::dump(){
    double output;
    unsigned int N = 0;
    char separator;
    std::string separatorChoice;
    std::cout << "Enter a separator type (comma, tab, pipe) " << std::endl;
    std::cin >> separatorChoice;

    /* if (separatorChoice == "comma")
    {
        std::ofstream outputFile("output.csv");
        separator = ',';
    }
    else if (separatorChoice == "tab")
    {
        std::ofstream outputFile("output.txt");
        separator = '\t';
    }
    else if (separatorChoice == "pipe")
    {
        std::ofstream outputFile("output.psv");
        separator = '|';
    }
    else
    {
        std::cout << "\nUnknown separator input. Default to .txt" <<std::endl;
        std::ofstream outputFile("output.txt");
        separator = '\t';
    } */

    std::ofstream outputFile;
    outputFile.open("output.txt");
    separator = '\t';
    
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Unable to open the file." << std::endl;
    }
    
    // Write data to the file using the selected separator
    outputFile << "N" << separator << "Series computation" << std::endl;
    while (N<maxiter){
        output = series.compute(N); // Here series is supposed to correspond to seriesPtr in the main
        outputFile << N << separator << output << std::endl;
        N += frequency;
    }

    double analyticPrediction = series.getAnalyticPrediction();
    outputFile << "\nConvergence" << separator << analyticPrediction << std::endl;

    outputFile.flush();
    outputFile.close();
    std::cout << "Data written to output file." << std::endl;

}

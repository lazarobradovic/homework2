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
    std::string separator;
    std::ofstream outputFile;

    // Get user input for file name and separator
    std::cout << "Enter file name: ";
    std::cin >> outputFile;

    std::cout << "Enter separator (csv/psv/txt, default is txt): ";
    std::cin >> separator;

    // Set the default file extension to .txt
    if (separator != "csv" && separator != "psv") {
        separator = "txt";
        std::cout << "File extension set to .txt"
    }

    // Append the appropriate extension to the file name
    outputFile += "." + separator;

    // Open the file using ofstream
    std::ofstream file(outputFile);
    
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

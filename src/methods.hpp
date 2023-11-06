//
//  methods.hpp
//  arthmeticseries
//
//  Created by Lazar Obradovic on 19.10.2023.
//

#ifndef methods_hpp
#define methods_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <numeric> //For accumulate operation
#include <vector>

class Series {
    
public:
    virtual double compute(unsigned int N) = 0;
    virtual double getAnalyticPrediction(); // Default should return NaN
};


class ComputeArithmetic : public Series {
    
public:
    double compute(unsigned int N);
};


class ComputePi : public Series {
    
public:
    double compute(unsigned int N);
    double getAnalyticPrediction();
};


class DumperSeries{

public:
    DumperSeries(Series &series) : series(series) {}
    
    virtual void dump() = 0;

protected:
    Series & series;
};


class PrintSeries : DumperSeries {
    
public:
    // Constructor to set frequency and maxiter
    PrintSeries(Series &series, int frequency, int maxiter)
    : DumperSeries(series), frequency(frequency), maxiter(maxiter) {}
    
    void dump();
    
private:
    int frequency; // I think I have to define them as private ? + Is frequency a vector or integer ?
    int maxiter;
    // No need to define Series *series : why? Because it inherits from DumperSeries, which has series initialized.
};


class WriteSeries : DumperSeries {
    
public:
    // Constructor to set frequency and maxiter
    WriteSeries(Series &series, int frequency, int maxiter)
    : DumperSeries(series), frequency(frequency), maxiter(maxiter) {}
    
    void dump();

    // char setSeparator(separatorChoice) to be defined
    
private:
    int frequency;
    int maxiter;
    std::string separatorChoice;
};

#endif /* methods_hpp */



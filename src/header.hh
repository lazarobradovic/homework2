#ifndef HEADER
#define HEADER

#include <string>
#include <iostream>

class Series {
    
public:
    virtual double compute(unsigned int N) = 0;
};

class ComputeArithmetic : public Series {
    
public:
    double compute(unsigned int N);
};

#endif

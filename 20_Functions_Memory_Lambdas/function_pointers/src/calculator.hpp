
#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <map>
#include <string>

// typedef double (*MathOperation)(double, double);
// OR
using  MathOperation = double (*)(double, double);

double add(double x, double y) {return x+y;}
double subtract(double x, double y) {return x-y;}
double multiply(double x, double y) {return x*y;}

#endif // CALCULATOR_HPP
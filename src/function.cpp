#include "../include/function.hpp"
#include <iostream>

double Function::factorial(int n){
    double foo = 1;
    if(n > 0)
        for(int i=1; i<(n+1); i++){
            foo *= i;
        }
    return foo;
}

Function::Function(int precision_user){

    precision = precision_user;
    x = std::vector<double>(precision);
    y = std::vector<double>(precision);
}

double Function::getx(int i){return x[i];};
double Function::gety(int i){return y[i];};
double Function::getPrecision(){return precision;};

void Function::setx(int i, double d){
        x[i] = d;
}

void Function::sety(int i, double d){
        y[i] = d;
}

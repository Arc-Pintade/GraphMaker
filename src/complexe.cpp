#include "../include/complexe.hpp"
#include <iostream>

Complexe::Complexe(double real_user, double imaginary_user){

    real = real_user;
    imaginary = imaginary_user;

}

double Complexe::getReal(){return real;};
double Complexe::getImaginary(){return imaginary;};

void Complexe::setReal(double real_user){real = real_user;};
void Complexe::setImaginary(double imaginary_user){imaginary = imaginary_user;};

void Complexe::mandelbrotSerie(Complexe c){
    Complexe foo(1,1);
    foo.setReal(real*real - imaginary*imaginary + c.getReal());
    foo.setImaginary(2*real*imaginary + c.getImaginary());
    real = foo.getReal();
    imaginary = foo.getImaginary();
}

void Complexe::translation(Complexe& c, Complexe a){
    c = Complexe::add(c,a);
}

void Complexe::rotation(Complexe& c, double angle){
    Complexe foo(cos(angle), sin(angle));
    c = Complexe::time(c,foo);
}

double Complexe::norme(Complexe c){
    double foo = 0;
    foo = c.getReal()*c.getReal() + c.getImaginary()*c.getImaginary();
    foo = sqrt(foo);
    return foo;
}

Complexe Complexe::invert(Complexe c){
    double zz = norme(c);
    Complexe foo(0,0);
    foo.setReal(c.getReal()/zz);
    foo.setImaginary(c.getImaginary()/zz);
    return foo;
}

Complexe Complexe::time(Complexe c1, Complexe c2){
    Complexe foo(0,0);
    foo.setReal((c1.getReal()*c2.getReal())-(c1.getImaginary()*c2.getImaginary()));
    foo.setImaginary((c1.getReal()*c2.getImaginary())+(c1.getImaginary()*c2.getReal()));
    return foo;
}

Complexe Complexe::add(Complexe c1, Complexe c2){
    Complexe foo(0,0);
    foo.setReal(c1.getReal()+c2.getReal());
    foo.setImaginary(c1.getImaginary()+c2.getImaginary());
    return foo;
}

void Complexe::print(Complexe c){
    if(c.getImaginary() > 0){
        if(c.getImaginary() != 1)
            std::cout<<c.getReal()<<"+"<<c.getImaginary()<<"i"<<std::endl;
        if(c.getImaginary() == 1)
            std::cout<<c.getReal()<<"+i"<<std::endl;
    }
    else if(c.getImaginary() < 0){
        if(c.getImaginary() != -1)
            std::cout<<c.getReal()<<c.getImaginary()<<"i"<<std::endl;
        if(c.getImaginary() == -1)
            std::cout<<c.getReal()<<"-i"<<std::endl;
    }
    else if(c.getImaginary() == 0)
        std::cout<<c.getReal()<<std::endl;
    else
        std::cout<<"problem with the print complexe function"<<std::endl;
}

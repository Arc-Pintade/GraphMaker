#ifndef complexe_hpp
#define complexe_hpp

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <cmath>

class Complexe{

    private :

        double real;
        double imaginary;

    public :

        Complexe(){};
        Complexe(double real_user, double imaginary_user);
        ~Complexe(){};

        double getReal();
        double getImaginary();

        void setReal(double real_user);
        void setImaginary(double imaginary_user);
        void mandelbrotSerie(Complexe c);

        static void translation(Complexe& c, Complexe a);
        static void rotation(Complexe& c, double angle);
        static double norme(Complexe c);
        static Complexe invert(Complexe c);
        static Complexe add(Complexe c1, Complexe c2);
        static Complexe time(Complexe c1, Complexe c2);
        static void print(Complexe c);

};

#endif

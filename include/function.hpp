#ifndef function_hpp
#define function_hpp

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <cmath>

class Function {

    private :

        int precision;
        std::vector<double> x;
        std::vector<double> y;

    public :

        Function(){};
        Function(int precision_user);
        ~Function(){};

        double getx(int i);
        double gety(int i);
        double getPrecision();

        void setx(int i, double d);
        void sety(int i, double d);

        void exponential(double coefficient, double argument, double intercepts);
        void sine(double amplitude, double pulse, double phase, double intercepts);
        void cosine(double amplitude, double pulse, double phase, double intercepts);

        static double factorial(int n);

};

#endif

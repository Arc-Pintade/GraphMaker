#ifndef canvas_hpp
#define canvas_hpp

#include "complexe.hpp"

double factorial(int n);

class Canvas{

    private :

        int xSize, ySize;
        int xUnits, yUnits;
        int thickLine; //3 default value

    public :

        Canvas(){};
        Canvas(int xSize_user, int ySize_user, int xUnits_user, int yUnits_user);
        ~Canvas(){};

        void drawXAxis(sf::RenderWindow& window, std::string name, int xMax, bool axis, bool scale, bool grid);
        void drawYAxis(sf::RenderWindow& window, std::string name, int yMax, bool axis, bool scale, bool grid);
        void drawTaylorOrdering(sf::RenderWindow& window, int n);
        void drawHelper(sf::RenderWindow& window, std::string name, int xPosition, int yPosition);

        void draw(sf::RenderWindow& window, Complexe c, sf::Color color);
        void drawFunction(sf::RenderWindow& window, std::string function, sf::Color color);
        void drawTaylor(sf::RenderWindow& window, std::string function, int order, sf::Color color);

};

#endif

#include "../include/canvas.hpp"
#include <iostream>

double factorial(int n){
    double foo = 1;
    if(n > 0)
        for(int i=1; i<(n+1); i++){
            foo *= i;
        }
    return foo;
}

Canvas::Canvas(int xSize_user, int ySize_user, int xUnits_user, int yUnits_user){
        xSize = xSize_user;
        ySize = ySize_user;
        xUnits = xUnits_user;
        yUnits = yUnits_user;
        thickLine = 3; //3 default value
}

void Canvas::drawXAxis(sf::RenderWindow& window, std::string name, int xMax, bool axis, bool scale, bool grid){
    sf::Color colorAxis(0,0,0,150);
    sf::Color colorGrid(0,0,0,100);
    sf::Color colorArrow(0,0,0,200);
// The axis
    sf::RectangleShape xAxis(sf::Vector2f(xSize-10, thickLine));
    sf::CircleShape tX(10.5, 3);
    xAxis.setPosition(10/2,ySize/2);
    xAxis.setFillColor(colorAxis);
    tX.setPosition(xSize/2-9,3);
    tX.setFillColor(colorArrow);
// The scale of axis
    if(scale){
        std::vector<sf::RectangleShape> scaleX(2*xMax);
        int size = 4;
        int step = xSize/(2*xMax);
        for(int i=1; i<(2*xMax); i++){
            scaleX[i].setSize(sf::Vector2f(thickLine,thickLine+2*size));
            scaleX[i].setFillColor(colorAxis);
            scaleX[i].setPosition(sf::Vector2f(i*step, ySize/2-size));
            if(i*step <= (xSize-20))
                window.draw(scaleX[i]);
        }
    }
    if(grid){
        std::vector<sf::RectangleShape> gridX(2*xMax);
        int step = xSize/(2*xMax);
        for(int i=1; i<(2*xMax); i++){
            gridX[i].setSize(sf::Vector2f(1,ySize-10));
            gridX[i].setFillColor(colorGrid);
            gridX[i].setPosition(sf::Vector2f(1+i*step, 5));
            if(i*step <= (xSize-20))
                window.draw(gridX[i]);
        }
    }
// The name axis
    sf::Font font;
    if (!font.loadFromFile("fonts/jsMath-cmmi10.ttf"))
        std::cout<<"error with the font file"<<std::endl;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setString(name);
    text.setFillColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(xSize-30,ySize/2.-40));
    if(axis){
        window.draw(xAxis);
        window.draw(tX);
        window.draw(text);
    }
}

void Canvas::drawYAxis(sf::RenderWindow& window, std::string name, int yMax, bool axis, bool scale, bool grid){
    sf::Color colorAxis(0,0,0,150);
    sf::Color colorGrid(0,0,0,100);
    sf::Color colorArrow(0,0,0,200);
// The axis
    sf::RectangleShape yAxis(sf::Vector2f(thickLine, ySize-10));
    sf::CircleShape tY(10.5, 3);
    yAxis.setPosition(xSize/2, 10/2);
    yAxis.setFillColor(colorAxis);
    tY.rotate(90);
    tY.setPosition(xSize-5,ySize/2-9);
    tY.setFillColor(colorArrow);
// The scale of axis
    if(scale){
        std::vector<sf::RectangleShape> scaleY(2*yMax);
        int size = 4;
        int step = ySize/(2*yMax);
        for(int i=1; i<(2*yMax); i++){
            scaleY[i].setSize(sf::Vector2f(thickLine+2*size, thickLine));
            scaleY[i].setFillColor(colorAxis);
            scaleY[i].setPosition(sf::Vector2f(xSize/2-size, i*step));
            if(i*step >= 15)
                window.draw(scaleY[i]);
        }
    }
    if(grid){
        std::vector<sf::RectangleShape> gridY(2*yMax);
        int step = ySize/(2*yMax);
        for(int i=1; i<(2*yMax); i++){
            gridY[i].setSize(sf::Vector2f(xSize-10, 1));
            gridY[i].setFillColor(colorGrid);
            gridY[i].setPosition(sf::Vector2f(5,1+i*step));
            if(i*step >= 15 )
                window.draw(gridY[i]);
        }
    }
// The name axis
    sf::Font font;
    if (!font.loadFromFile("fonts/jsMath-cmmi10.ttf"))
        std::cout<<"error with the font file"<<std::endl;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setString(name);
    text.setFillColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(xSize/2.+20, 0));
    if(axis){
        window.draw(yAxis);
        window.draw(tY);
        window.draw(text);
    }
}

void Canvas::drawTaylorOrdering(sf::RenderWindow& window, int n){
    sf::RectangleShape back(sf::Vector2f(400,41));
    sf::Font font;
    if (!font.loadFromFile("fonts/texgyredejavu-math.otf"))
        std::cout<<"error with the font file"<<std::endl;
    sf::Text text;
    sf::Text warning;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setStyle(sf::Text::Bold);
    text.setString("Taylor expansion order : "+std::to_string(n));
    if(n < 40){
        text.setFillColor(sf::Color::Blue);
    }
    else if(n >= 40 and n < 50 ){
        text.setFillColor(sf::Color::Red);
    }
    else{
        text.setFillColor(sf::Color::Red);
        warning.setFont(font);
        warning.setCharacterSize(50);
        warning.setFillColor(sf::Color::Red);
        warning.setStyle(sf::Text::Bold);
        warning.setString("Tu pousses le bouchon \n un peu trop loin maurice !!!");
        warning.setPosition(sf::Vector2f(xSize/4,ySize/4));
        warning.rotate(30);
    }
    window.draw(back);
    window.draw(text);
    window.draw(warning);
}

void Canvas::drawHelper(sf::RenderWindow& window, std::string name, int xPosition, int yPosition){
    sf::Color colorBack(150,0,0,50);
    sf::RectangleShape rect(sf::Vector2f(5,ySize));
    sf::RectangleShape back(sf::Vector2f(400, ySize));
    rect.setPosition(sf::Vector2f(xSize,0));
    rect.setFillColor(sf::Color::Black);
    back.setPosition(sf::Vector2f(xSize,0));
    back.setFillColor(colorBack);
    sf::Font font;
    if (!font.loadFromFile("fonts/texgyredejavu-math.otf"))
        std::cout<<"error with the font file"<<std::endl;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Black);
    text.setString(name);
    text.setPosition(sf::Vector2f(xPosition,yPosition));
    window.draw(rect);
    window.draw(back);
    window.draw(text);
}

void Canvas::draw(sf::RenderWindow& window, Complexe c, sf::Color color){
    sf::RectangleShape v(sf::Vector2f(3,11));
    sf::RectangleShape h(sf::Vector2f(11,3));
    double xCanvas1 = xSize/2 + c.getReal()*((xSize-10)/((2.*xUnits)));
    double yCanvas1 = ySize/2 - c.getImaginary()*((ySize-10)/((2.*yUnits)));
    double xCanvas2 = xSize/2 + c.getReal()*((xSize-10)/((2.*xUnits)));
    double yCanvas2 = ySize/2 - c.getImaginary()*((ySize-10)/((2.*yUnits)));
    sf::CircleShape point;
    v.setFillColor(color);
    v.setPosition(xCanvas1+1,yCanvas1-4);
    h.setFillColor(color);
    h.setPosition(xCanvas2-3,yCanvas2);
    window.draw(v);
    window.draw(h);
}

void Canvas::drawFunction(sf::RenderWindow& window, std::string function, sf::Color color){
    double radius = 1.5;
    int prec =1000;
// Built of the function
    double xCanvas[prec]{0};
    double yCanvas[prec]{0};
    for(int i=0; i<prec; i++){
        xCanvas[i] = 5 + i*(xSize-10)*(1./prec);
        if(function == "trivial")
            yCanvas[i] = ySize/2.;
        else if(function == "exp")
            yCanvas[i] = ySize/2. - exp(-xUnits + i*xUnits*(2./prec))*((ySize)/(2.*yUnits));
        else if(function == "cos")
            yCanvas[i] = ySize/2. - cos(-xUnits + i*xUnits*(2./prec))*((ySize)/(2.*yUnits));
        else if(function == "sin")
            yCanvas[i] = ySize/2. - sin(-xUnits + i*xUnits*(2./prec))*((ySize)/(2.*yUnits));
        else if(function == "ch")
            yCanvas[i] = ySize/2. - cosh(-xUnits + i*xUnits*(2./prec))*((ySize)/(2.*yUnits));
        else if(function == "sh")
            yCanvas[i] = ySize/2. - sinh(-xUnits + i*xUnits*(2./prec))*((ySize)/(2.*yUnits));
        else if(function == "ln")
            yCanvas[i] = ySize/2. - log(-xUnits + i*xUnits*(2./prec) + 1)*((ySize)/(2.*yUnits));
        else
            std::cout<<"error with drawFunction"<<std::endl;
    }
// Draw in Canvas
    std::vector<sf::CircleShape> point(prec);
    for(int i=0; i<prec; i++){
        point[i].setRadius(radius);
        point[i].setFillColor(color);
        point[i].setPosition(xCanvas[i],yCanvas[i]);
        window.draw(point[i]);
    }
}

void Canvas::drawTaylor(sf::RenderWindow& window, std::string function, int order, sf::Color color){
    double radius = 1.5;
    int prec =1000;
// Built of the function
    double xCanvas[prec]{0};
    double yCanvas[prec]{0};
    for(int i=0; i<prec; i++){
        xCanvas[i] = 5 + i*(xSize-10)*(1./prec);
        yCanvas[i] = ySize/2.;
        if(function == "trivial")
            for(int j=0; j<order; j++)
                yCanvas[i] -= 0;
        else if(function == "exp")
            for(int j=0; j<order; j++)
                yCanvas[i] -= (pow(-xUnits + i*xUnits*(2./prec), j)/factorial(j))*((ySize)/(2.*yUnits));
        else if(function == "cos")
            for(int j=0; j<order; j++)
                yCanvas[i] -= pow(-1,j)*(pow(-xUnits + i*xUnits*(2./prec), 2*j)/factorial(2*j))*((ySize)/(2.*yUnits));
        else if(function == "sin")
            for(int j=0; j<order; j++)
                yCanvas[i] -= pow(-1,j)*(pow(-xUnits + i*xUnits*(2./prec), 2*j+1)/factorial(2*j+1))*((ySize)/(2.*yUnits));
        else if(function == "ch")
            for(int j=0; j<order; j++)
                yCanvas[i] -= (pow(-xUnits + i*xUnits*(2./prec), 2*j)/factorial(2*j))*((ySize)/(2.*yUnits));
        else if(function == "sh")
            for(int j=0; j<order; j++)
                yCanvas[i] -= (pow(-xUnits + i*xUnits*(2./prec), 2*j+1)/factorial(2*j+1))*((ySize)/(2.*yUnits));
        else if(function == "ln")
            for(int j=1; j<order; j++)
                yCanvas[i] -= pow(-1,j+1)*(pow(-xUnits + i*xUnits*(2./prec), j)/((double)j))*((ySize)/(2.*yUnits));
        else
            std::cout<<"error with drawFunction"<<std::endl;
    }
// Draw in Canvas
    std::vector<sf::CircleShape> point(prec);
    for(int i=0; i<prec; i++){
        point[i].setRadius(radius);
        point[i].setFillColor(color);
        point[i].setPosition(xCanvas[i],yCanvas[i]);
        window.draw(point[i]);
    }
}


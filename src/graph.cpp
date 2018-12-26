#include "../include/canvas.hpp"

#include <iostream>


using namespace std;

//////////////////////////
//                      //
//  For no problems     //
//  use multiple of 10  //
//                      //
//////////////////////////


int main (){

    cout<<"Hello World !"<<endl;

    Complexe c0(2,4);
    Complexe::print(c0);
    Complexe::print(Complexe::invert(c0));

    Complexe c1(1,1);
    Complexe c2(-2,1);
    Complexe c3(0,0);
    Complexe::print(Complexe::add(c1,c2));
    Complexe::print(Complexe::time(c1,c2));
    Complexe::print(c3);


    vector<int> windowSize(2);
    windowSize[0]=1000;
    windowSize[1]=800;
    int precision = 1000;
    int order = 0;
    bool axis = true;
    bool scale = true;
    bool grid = true;
    string func = "trivial";
    int angle = 90;
    cout<<"The complexe rotation is : "<<angle<<endl;

    int units = 10;

    sf::RenderWindow window(sf::VideoMode(windowSize[0]+400, windowSize[1]), "GraphMaker");
    Canvas c(windowSize[0], windowSize[1], units, units);

    while (window.isOpen()){

        window.clear(sf::Color::White);
        c.drawXAxis(window, "x", units, axis, scale, grid);
        c.drawYAxis(window, "y", units, axis, scale, grid);
        c.drawHelper(window, " (E) : exponential \n (S) : sine \n (C) : cosine \n (L) : logarithm \n (Z) : trivial \n \n (T/Y) : axis(on/off) \n (G/H) : scale(on/off) \n (B/N) : grid(on/off) \n \n (O) : return to order 0 \n (Up) : order up \n (Down) : order down ",windowSize[0]+10 ,10);

        c.drawFunction(window, func, sf::Color::Red);
        c.drawTaylor(window, func, order, sf::Color::Blue);
        c.drawTaylorOrdering(window, order);

        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Up)
                    order++;
                if (event.key.code == sf::Keyboard::Down)
                    if(order>0)
                        order--;
                if (event.key.code == sf::Keyboard::T)
                    axis = true;
                if (event.key.code == sf::Keyboard::Y)
                    axis = false;
                if (event.key.code == sf::Keyboard::G)
                    scale = true;
                if (event.key.code == sf::Keyboard::H)
                    scale = false;
                if (event.key.code == sf::Keyboard::B)
                    grid = true;
                if (event.key.code == sf::Keyboard::N)
                    grid = false;
                if (event.key.code == sf::Keyboard::Z)
                    func = "trivial";
                if (event.key.code == sf::Keyboard::E)
                    func = "exp";
                if (event.key.code == sf::Keyboard::C)
                    func = "cos";
                if (event.key.code == sf::Keyboard::S)
                    func = "sin";
                if (event.key.code == sf::Keyboard::L)
                    func = "ln";
                if (event.key.code == sf::Keyboard::O)
                    order = 0;
            }
        }
        window.display();
    }

    return 0;
}

#include "../include/Canvas.hpp"
#include "../include/Function.hpp"
#include "../include/Complexe.hpp"

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
    unsigned int angle = 1;
    cout<<"The complexe rotation is : "<<(angle/(2*M_PI))<<endl;

    int units = 10;
/*    do{
        cout<<"Define the maximum of x (<70) : ";
        cin>>units;
    }while(units < 0 && units > 70);*/
    string option;
    do{
        cout<<"Take a Taylor expansion : 'exp', 'sin' or 'cos' : ";
        cin>>option;
    }while (option!="exp" && option!="sin" && option!="cos");

    cout<<"The order is : "<<order<<endl;

    sf::RenderWindow window(sf::VideoMode(windowSize[0]+1, windowSize[1]+1), "GraphMaker");
    Canvas c(windowSize[0], windowSize[1]);

    Complexe z(2, 4, windowSize[0], windowSize[1], units, units, precision);

    Function f1(windowSize[0], windowSize[1], units, units, precision, sf::Color::Blue);
    Function f2(windowSize[0], windowSize[1], units, units, precision, sf::Color::Red);

    while (window.isOpen()){

        window.clear(sf::Color::White);
        c.drawXAxis(window, units, true, false);
        c.drawYAxis(window, units, true, false);
        c.drawTaylorOrdering(window, order);
        if(option == "exp")
            f2.buildExponantial(1, 1, 0);
        else
            f2.buildWave(option, 1, 1, 0, 0);
        f2.draw(window);
        f1.buildTaylor(order, option);
        f1.draw(window);
        z.draw(window);

        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Up){
                    order++;
                    cout<<"The order is : "<<order<<endl;
                }
                if (event.key.code == sf::Keyboard::Down){
                    if(order != 0)
                        order--;
                    cout<<"The order is : "<<order<<endl;
                }
                if (event.key.code == sf::Keyboard::Left){
                    z.rotation(angle/(2*M_PI));
                }
                if (event.key.code == sf::Keyboard::Right){
                    z.rotation(-angle/(2*M_PI));
                }
            }
        }
        window.display();
    }

    return 0;
}

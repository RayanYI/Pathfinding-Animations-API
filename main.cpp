#include "CSubMenu.h"
#include<iostream>
int main(){

    sf::RenderWindow window({ 1600 ,900 }, "test");
    sf::Font font;
    sf::Event event;
    font.loadFromFile("./assets/fonts/Oswald-Bold.ttf");
    CSubMenu left(300,450,"AlgoText",font,0);
    left.AddChoice("1- BFS");
    left.AddChoice("2- DFS");
    left.AddChoice("3- A*");

    CSubMenu mid(700,450,"Dimensions",font,1);
    mid.AddChoice("4- 10");
    mid.AddChoice("5- 20");
    mid.AddChoice("6- 40");

    CSubMenu right(1100,450,"Speed",font,2);
    right.AddChoice("7- 0.25");
    right.AddChoice("8- 0.5");
    right.AddChoice("9- 1");
    while(window.isOpen()){
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type==sf::Event::KeyPressed){
                switch (event.key.code)
                {
                    case sf::Keyboard::Num1:
                        left.SetCurrentChoice(0);
                        break;

                    case sf::Keyboard::Num2:
                        left.SetCurrentChoice(1);
                        break;

                    case sf::Keyboard::Num3:
                        left.SetCurrentChoice(2);
                        break;
                    case sf::Keyboard::Num4:
                        mid.SetCurrentChoice(0);
                    break;
                    case sf::Keyboard::Num5: 
                        mid.SetCurrentChoice(1);
                    break;
                    case sf::Keyboard::Num6:
                        mid.SetCurrentChoice(2);
                    break;
                    case sf::Keyboard::Num7:
                        right.SetCurrentChoice(0);
                    break;
                    case sf::Keyboard::Num8:
                        right.SetCurrentChoice(1);
                    break;
                    case sf::Keyboard::Num9:
                        right.SetCurrentChoice(2);
                    break;
                
                }
            }
            
        }
        window.clear();
        window.draw(*left.GetTitle());
        for(auto const&x:left.GetList()){
            window.draw(*x);
        }
        window.draw(*mid.GetTitle());
        for(auto const&x:mid.GetList()){
            window.draw(*x);
        }
        window.draw(*right.GetTitle());
        for(auto const&x:right.GetList()){
            window.draw(*x);
        }
        window.display();
    }

    return 0;
}
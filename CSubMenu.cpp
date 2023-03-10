#include "CSubMenu.h"

CSubMenu::CSubMenu(float x,float y,std::string title,sf::Font font,int p_default){
    a_font=font;
    a_x=x;
    a_y=y;
    a_curr=p_default;
    a_title=new sf::Text(title,a_font,35);
    a_title->setPosition(a_x,a_y);
    a_title->setColor(sf::Color::Red);
}

void CSubMenu::AddChoice(std::string p_text){
    a_list.push_back(new sf::Text(p_text,a_font,25));
    a_list.back()->setPosition(a_x+20.f,a_y+a_list.size()*50.f);
    if(a_list.size()-1==a_curr)a_list.back()->setColor(sf::Color(0,255,255));
}

void CSubMenu::SetCurrentChoice(int i){
    if(i!=a_curr){
        a_list[a_curr]->setColor(sf::Color::White);
        a_list[i]->setColor(sf::Color(0,255,255));
        a_curr=i;
    }
}

CSubMenu::~CSubMenu(){
    delete a_title;
    a_title=nullptr;
    for(auto &x:a_list){
        delete x;
        x=nullptr;
    }
}
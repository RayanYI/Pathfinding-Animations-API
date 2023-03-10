#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include<vector>

class CSubMenu{
    private:
        float a_x=0.0f,a_y=0.0f;
        int a_curr=0;
        sf::Font a_font;
        sf::Text* a_title=nullptr;
        std::vector<sf::Text*>a_list;
    public:
        CSubMenu(float x,float y,std::string title, sf::Font font,int p_default);
        void AddChoice(std::string p_text);
        void SetCurrentChoice(int i);
        sf::Text* GetTitle(void)const{return(a_title);};
        std::vector<sf::Text*> GetList(void)const{return(a_list);};
        ~CSubMenu();
};
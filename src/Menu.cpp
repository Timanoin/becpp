#include "Menu.h"
#include "constants.h"

Menu::Menu(SCREEN* u8g2) : listOptions(), cursor(listOptions.begin()) 
{
  this->u8g2 = u8g2;
}

Menu::~Menu()
{
  
}

void Menu::addOption(MenuOption* option)
{
  listOptions.push_back(option);
}

void Menu::addOption(MenuOption* option, int pos)
{
  MENU_IT it;
  for (int i = 0; i < pos; i++)
  {
    it++;
  }
  listOptions.insert(it, option);
}

void Menu::next(){
  if (++cursor == listOptions.end()){
    cursor = listOptions.begin();
  }    
};

void Menu::prev(){
  if (--cursor == listOptions.begin()){
    cursor = listOptions.end();
  }
};

// TODO:
//void Menu::select();
//void Menu::back();
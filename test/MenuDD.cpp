#include "MenuDD.h"
#include "images/beta.xbm"
#include "images/omega.xbm"
#include "images/phi.xbm"
#include "images/psi.xbm"


MenuDD::MenuDD() : Menu() {}

void Menu::addOption(MenuOption* option)
{
  listOptions.push_back(option);
}

void MenuDD::addOption(MenuOption* option, int pos)
{
  menuIt it;
  for (int i = 0; i < pos; i++)
  {
    it++;
  }
  listOptions.insert(it, option);
}

void MenuDD::next(){
  if (++cursor == listOptions.end()){
    cursor = listOptions.begin();
  }    
};

void MenuDD::prev(){
  if (--cursor == listOptions.begin()){
    cursor = listOptions.end();
  }
};

// TODO:
//void MenuDD::select();
//void MenuDD::back();

void MenuDD::display()
{
  
}
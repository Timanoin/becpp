#include "Menu.h"

Menu::Menu() : listOptions(), cursor(listOptions.begin()) {}

void Menu::addOption(MenuOption* option)
{
  listOptions.push_back(option);
}

void Menu::addOption(MenuOption* option, int pos)
{
  menuIt it;
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
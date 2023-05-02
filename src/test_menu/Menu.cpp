#include "Menu.h"
#include "constants.h"
#include <typeinfo>

Menu::Menu(SCREEN* u8g2) : listOptions(), cursor(listOptions.begin()) 
{
  this->u8g2 = u8g2;
}

Menu::~Menu()
{
  
}

void Menu::init()
{
  cursor = listOptions.begin();
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
  if (++cursor == listOptions.end())
  {
    cursor = listOptions.begin();
  }  
};

void Menu::prev(){
  if (cursor == listOptions.begin()){
    cursor = listOptions.end();
    cursor--;
  }
  else
  {
    cursor--;
  }
};

// TODO:
void Menu::select()
{
  if (menuPtr != nullptr)
  {
    if (typeid(this) == typeid(MenuDD))
    stackMenu.push(currMenu);
    currMenu = menuPtr;
  }
}

void Menu::back()
{
  if (!stackMenu.empty())
  currMenu = stackMenu.pop();
}

void setCurrMenu()
{
  currMenu = this;
}
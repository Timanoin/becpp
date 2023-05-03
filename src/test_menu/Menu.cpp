#include "Menu.h"
#include "constants.h"
#include <typeinfo>

// Initialisation of static attributes
Menu** Menu::currMenu = new Menu*;
std::stack<Menu*> Menu::menuStack;

// Constructor of class Menu
Menu::Menu() : listOptions(), cursor(listOptions.begin()) {}

// Destructor of class Menu
Menu::~Menu() {}

// Adds an option to the bottom of the menu.
void Menu::addOption(MenuOption* option)
{
  listOptions.push_back(option);
}

// Adds an option at the desired position in the menu.
void Menu::addOption(MenuOption* option, int pos)
{
  MENU_IT it;
  for (int i = 0; i < pos; i++)
  {
    it++;
  }
  listOptions.insert(it, option);
}

// Call this in the setup part of the program to properly initialize the menu *after* adding options.
void Menu::init()
{
  cursor = listOptions.begin();
}

// Moves the cursor to the next option in the list.
void Menu::next(){
  if (++cursor == listOptions.end())
  {
    cursor = listOptions.begin();
  }  
};

// Moves the cursor to the previous option in the list.
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

// Goes back one layer in the menu.
void Menu::back()
{
  if (!menuStack.empty())
  {
    Menu* m = menuStack.top();
    m->setCurrMenu();
    menuStack.pop();
    Serial.print("Back");
  }
}

// Sets the menu as the current menu displayed on screen.
void Menu::setCurrMenu()
{
  (*currMenu) = this;
}
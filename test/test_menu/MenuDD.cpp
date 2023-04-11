#include "MenuDD.h"
#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>


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
  u8g2.drawLine(0,0,0,128);
  u8g2.drawLine(128,0,128,128);
  for (int i = 0; i < 5; i++)
  {
    u8g2.drawLine(0,32*i,128,32*i);
    // TODO: afficher les options
  }
  // TODO: afficher curseur
}
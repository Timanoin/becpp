#include "MenuCart.h"
#include "constants.h"
#include <U8g2lib.h>
#include <typeinfo>
#include <string>
#include <sstream>
#include <iomanip> // for std::setprecision

// Constructor of class Menu Drop Down.
MenuCart::MenuCart() : Menu() {}

// Display the menu on the screen.
void MenuCart::display()
{

  float total = 0;
  for (int i = 0; i < IDLAST; i++)
  {
    total += CART[i]->getCost() * (*(CART[i]->getQuantity()));
  }
  SCREEN_RESET_FONT();
  int pos = std::to_string((float)total).find(".");
  SCREEN.drawStr(10,116,std::to_string((float)total).substr(0,pos+3).c_str());
  SCREEN.drawStr(10,24,"PANIER");
  SCREEN.drawStr(10,96,"TOTAL ($) :");

}

void MenuCart::select()
{

}
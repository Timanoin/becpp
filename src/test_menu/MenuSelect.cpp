#include "MenuSelect.h"
#include <U8g2lib.h>
#include <string>


// Constructor of class Menu Drop Down.
MenuSelect::MenuSelect(int i) : Menu(), index(i) {}

// Display the menu on the screen.
void MenuSelect::display()
{
  const int offX1 = 10;
  const int offY1 = 16;
  const int offX2 = 10;
  const int offY2 = 36;
  SCREEN.drawTriangle(0+offX1,16+offY1,16+offX1,16+offY1,8+offX1,0+offY1);
  SCREEN.drawTriangle(0+offX2,0+offY2,16+offX2,0+offY2,8+offX2,16+offY2);
  SCREEN_RESET_FONT();
  SCREEN.drawStr(32,36,std::to_string(q).c_str());
  SCREEN.drawStr(10,72,CART[index]->getDesc1());
  SCREEN.drawStr(10,84,CART[index]->getDesc2());
  SCREEN.drawStr(10,96,CART[index]->getName());
  int pos = std::to_string((float)(CART[index]->getCost())).find(".");
  SCREEN.drawStr(10,108,std::to_string((float)(CART[index]->getCost())).substr(0,pos+3).c_str());
}

// Call this when opening the Menu Select
void MenuSelect::open()
{
  old_q = *(CART[index]->getQuantity());
  q = old_q;
}

// Select the desired quantity of food.
void MenuSelect::select()
{
  *(CART[index]->getQuantity()) = q;
  if (!menuStack.empty())
  {
    Menu* m = menuStack.top();
    m->setCurrMenu();
    menuStack.pop();
  }
}
// Doesn't select the food.
void MenuSelect::back()
{
  *(CART[index]->getQuantity()) = old_q;
  if (!menuStack.empty())
  {
    Menu* m = menuStack.top();
    m->setCurrMenu();
    menuStack.pop();
  }
}
// Adds 1 to the counter.
void MenuSelect::next()
{
  if (q>0) q--;
}
// MRemoves 1 from the counter.
void MenuSelect::prev()
{
  if (q<99) q++;
}

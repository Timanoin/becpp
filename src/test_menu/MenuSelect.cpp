#include "MenuSelect.h"
#include <U8g2lib.h>

// Constructor of class Menu Drop Down.
MenuSelect::MenuSelect(int i) : Menu(), index(i) {}

// Display the menu on the screen.
void MenuSelect::display()
{
  SCREEN.drawLine(0,0,0,127);
  SCREEN.drawLine(0,0,127,0);
  SCREEN.drawLine(127,0,127,127);
  SCREEN.drawLine(0,127,127,127);
  //SCREEN.draw
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
  if (q<99) q++;
}
// MRemoves 1 from the counter.
void MenuSelect::prev()
{
  if (q>0) q--;
}

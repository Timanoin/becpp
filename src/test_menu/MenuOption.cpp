#include "MenuOption.h"

// Constructor of the MenuOption class.
MenuOption::MenuOption(const char* text, unsigned char* icon, Menu* menuPtr) : 
text(text), icon(icon), menuPtr(menuPtr){};

// Display the option on the screen.
void MenuOption::display(int Y)
{
  SCREEN.drawXBM(0,32*Y,32,32,icon);
  SCREEN.drawStr(32+24,32*Y+24,text);
}

// Get the next menu pointer.
Menu* MenuOption::getMenuPtr()
{
  return menuPtr;
}
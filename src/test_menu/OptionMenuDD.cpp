#include "OptionMenuDD.h"
#include "constants.h"

OptionMenuDD::OptionMenuDD(const char* text, unsigned char* icon, Menu* menuPtr) : OptionMenu(text, icon), menuPtr(menuPtr) {}

// Display the option on the screen.
void OptionMenuDD::display(int Y)
{
  SCREEN.drawXBM(0,32*Y,32,32,icon);
  SCREEN.drawStr(32+24,32*Y+24,text);
}

// Get the next menu pointer.
Menu* OptionMenuDD::getMenuPtr()
{
  return menuPtr;
}

void OptionMenuDD::init()
{

}
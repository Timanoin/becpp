#include "MenuFood.h"
#include <U8g2lib.h>


MenuFood::MenuFood() : Menu() {}

// Display the menu on the screen.
void MenuFood::display()
{
  ((OptionMenuFood*)(*cursor))->display(0);
}

void MenuFood::init()
{

  for (MENU_IT it = listOptions.begin(); it != listOptions.end(); it++)
  {
    (*it)->init();
  }
  cursor = listOptions.begin();
}

// Select an option.
void MenuFood::select()
{
  if (((OptionMenuFood*)(*cursor))->getMenuPtr() != nullptr)
  {
    menuStack.push(*currMenu);
    ((OptionMenuFood*)(*cursor))->getMenuPtr()->setCurrMenu();
    ((MenuSelect*)(*currMenu))->open();
  }
}
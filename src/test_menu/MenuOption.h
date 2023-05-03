#ifndef __MENU_OPTION__
#define __MENU_OPTION__

#include "constants.h"
#include <U8g2lib.h>

class Menu;

// The MenuOption class provides the ability to create an option for a menu.
class MenuOption
{
  protected:
  // Text of the option.
  const char* text;
  // Icon of the option.
  unsigned char* icon;
  // Next menu if this option is selected.
  Menu* menuPtr;

  public:
  // Constructor of the MenuOption class.
  MenuOption(const char* text, unsigned char* icon, Menu* menuPtr);
  // Display the option on the screen.
  void display(int Y);
  // Get the next menu pointer.
  Menu* getMenuPtr();
};

#endif
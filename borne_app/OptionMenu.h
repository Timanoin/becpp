#ifndef __MENU_OPTION__
#define __MENU_OPTION__

#include "constants.h"
#include <U8g2lib.h>

class Menu;

// The OptionMenu class provides the ability to create an option for a menu.
class OptionMenu
{
  protected:
  // Text of the option.
  const char* text;
  // Icon of the option.
  unsigned char* icon;

  public:
  // Constructor of the OptionMenu class.
  OptionMenu(const char* text, unsigned char* icon);
  // Display the option on the screen.
  virtual void display(int Y) = 0;
  virtual void init() = 0;
  virtual void executeFuncPtr() = 0;
};

#endif
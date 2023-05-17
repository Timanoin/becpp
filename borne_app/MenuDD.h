#ifndef __MENUDD__
#define __MENUDD__

#include "Menu.h"
#include "OptionMenuDD.h"
#include <list>

// The class MenuDD is a subclass of Menu. It provides a drop-down menu for the user.
class MenuDD : public Menu
{
  public:
  // Constructor of class Menu Drop Down.
  MenuDD();

  // Display the menu on the screen.
  virtual void display();
  // Select an option.
  virtual void select();
};

#endif
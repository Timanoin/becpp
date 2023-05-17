#ifndef __MENUFOOD__
#define __MENUFOOD__

#include "Menu.h"
#include "OptionMenuFood.h"

// The class MenuFood is a subclass of Menu. It provides a drop-down menu for the usermenu to display food.
class MenuFood : public Menu
{
  public:
  // Constructor of class Menu Drop Down.
  MenuFood();
  // Initialize menu and options
  virtual void init();

  // Display the menu on the screen.
  virtual void display();
  // Select an option.
  virtual void select();
};

#endif
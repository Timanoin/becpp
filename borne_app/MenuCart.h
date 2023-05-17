#ifndef __MENUCART__
#define __MENUCART__

#include "Menu.h"
#include "constants.h"

// The class MenuCart is a subclass of Menu. It provides a menu that displays the total cost of the cart.
class MenuCart : public Menu
{
  public:
  // Constructor of class Menu Select.
  MenuCart();

  // Display the menu on the screen.
  virtual void display();
  virtual void select();
};

#endif
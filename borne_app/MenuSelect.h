#ifndef __MENUSELECT__
#define __MENUSELECT__

#include "Menu.h"
#include "constants.h"

// The class MenuSelect is a subclass of Menu. It provides a menu to select a value.
class MenuSelect : public Menu
{
  public:
  int index;
  int old_q;
  int q;
  // Constructor of class Menu Select.
  MenuSelect(int index);

  // Call this when opening the Menu Select
  void open();

  // Display the menu on the screen.
  virtual void display();
  // Select an option.
  virtual void select();
  // Select an option.
  virtual void back();
  // Adds 1 to the counter.
  virtual void next();
  // MRemoves 1 from the counter.
  virtual void prev();
};

#endif
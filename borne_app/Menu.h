#ifndef __MENU__
#define __MENU__
#include "constants.h"
#include "OptionMenu.h"
#include <list>
#include <stack>

// Redefinition of the std::list<OptionMenu*>::iterator class
typedef std::list<OptionMenu*>::iterator MENU_IT;

class OptionMenu;

// The Menu class allows the user to create, manage and display a menu. 
class Menu
{
  protected:
  // List of options of the menu.
  std::list<OptionMenu*> listOptions;
  // Current position of the cursor in the menu.
  MENU_IT cursor;

  public:
  // Constructor of class Menu
  Menu();
  // Destructor of class Menu
  ~Menu();

  // Adds an option to the bottom of the menu.
  void addOption(OptionMenu* option);
  // Adds an option at the desired position in the menu.
  void addOption(OptionMenu* option, int pos);
  // Call this in the setup part of the program to properly initialize the menu *after* adding options.
  virtual void init();

  // Moves the cursor to the next option in the list.
  virtual void next();
  // Moves the cursor to the previous option in the list.
  virtual void prev();
  // Selects the option in the menu. Depending on the menu, this function may have different behaviors
  virtual void select() = 0;
  // Goes back one layer in the menu.
  void back();

  // Sets the menu as the current menu displayed on screen.
  void setCurrMenu();
  // Display the screen (to be used in the do while (u8g2.nextPage()) loop)
  virtual void display() = 0;

  // Static attributes

  // Current menu displayed on screen and being managed
  static Menu** currMenu;
  // Last menus jumped into
  static std::stack<Menu *> menuStack;
};

#endif
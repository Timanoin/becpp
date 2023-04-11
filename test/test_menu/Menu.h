#ifndef __MENU__
#define __MENU__
#include "MenuOption.h"
#include <list>

typedef std::list<MenuOption*>::iterator menuIt;

class Menu
{
  protected:
  std::list<MenuOption*> listOptions;
  menuIt cursor;

  public:
  Menu();

  void addOption(MenuOption* option);
  void addOption(MenuOption* option, int pos);

  void next();
  void prev();
  void select();
  void back();

  virtual void display();
};

#endif
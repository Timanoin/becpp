#ifndef __MENU__
#define __MENU__
#include "constants.h"
#include "MenuOption.h"
#include <list>

typedef std::list<MenuOption*>::iterator MENUIT;

class Menu
{
  protected:
  std::list<MenuOption*> listOptions;
  MENU_IT cursor;
  SCREEN* u8g2;

  public:
  Menu(SCREEN* u8g2);
  ~Menu();

  void addOption(MenuOption* option);
  void addOption(MenuOption* option, int pos);

  void next();
  void prev();
  void select();
  void back();

  virtual void display() = 0;
};

#endif
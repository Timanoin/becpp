#ifndef __MENU__
#define __MENU__
#include "constants.h"
#include "MenuOption.h"
#include <list>
#include <stack>

typedef std::list<MenuOption*>::iterator MENU_IT;

class Menu
{
  protected:
  std::list<MenuOption *> listOptions;
  MENU_IT cursor;
  SCREEN* u8g2;
  static std::stack<Menu *> menuStack;


  public:
  Menu(SCREEN* u8g2);
  ~Menu();

  void init();
  void addOption(MenuOption* option);
  void addOption(MenuOption* option, int pos);

  void next();
  void prev();
  void select();
  void back();

  static Menu *currMenu;

  virtual void display() = 0;
};

#endif
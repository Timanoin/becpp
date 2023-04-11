#ifndef __MENUDD__
#define __MENUDD__
#include "MenuOption.h"
#include "Menu.h"
#include <list>

class MenuDD : public Menu
{
  public:
  MenuDD();

  void addOption(MenuOption* option, int pos);

  void next();
  void prev();
  void select();
  void back();

  virtual void display();

};
#endif
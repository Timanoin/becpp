#ifndef __MENUDD__
#define __MENUDD__

#include "Menu.h"
#include "MenuOption.h"
#include <list>
class MenuDD : public Menu
{
  public:
  MenuDD(SCREEN* u8g2);

  virtual void display();

};

#endif
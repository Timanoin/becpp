#ifndef __MENUOPTION__
#define __MENUOPTION__

#include "constants.h"
class MenuOption
{
  protected:
  const char* text;
  unsigned char* icon;
  void (*func_ptr)(void);
  SCREEN* u8g2;

  public:
  MenuOption(const char* text, unsigned char* icon, void (*func_ptr)(void), SCREEN* u8g2);
  void display(int Y);
};

#endif
#ifndef __ARTICLE__
#define __ARTICLE__
#include "constants.h"
#include "OptionMenu.h"
#include "MenuSelect.h"
#include <list>
#include <string>

class OptionMenuFood : public OptionMenu
{
  protected:
  int index;
  float cost;
  MenuSelect* menuPtr;

  public:
  OptionMenuFood(int index);
  ~OptionMenuFood();

  virtual void init();
  virtual void display(int Y);
  // Get the next menu pointer.
  Menu* getMenuPtr();
  virtual void executeFuncPtr();
};

#endif
#ifndef __OPTIONMENUDD__
#define __OPTIONMENUDD__

#include "OptionMenu.h"

// The OptionMenuDD class provides the ability to create an option for a drop-down menu.
class OptionMenuDD : public OptionMenu
{
  protected:
  // Next menu if this option is selected.
  Menu* menuPtr;
  void (*funcPtr)(void);
  public:
  // Constructor of the OptionMenu class.
  OptionMenuDD(const char* text, unsigned char* icon, Menu* menuPtr, void (*funcPtr)(void));
  // Display the option on the screen.
  virtual void display(int Y);
  // Get the next menu pointer.
  Menu* getMenuPtr();
  virtual void init();
  virtual void executeFuncPtr();
};

#endif
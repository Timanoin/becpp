#include "MenuDD.h"
#include <U8g2lib.h>
#include <typeinfo>

// Constructor of class Menu Drop Down.
MenuDD::MenuDD() : Menu() {}

// Display the menu on the screen.
void MenuDD::display()
{
  int pos = std::distance(listOptions.begin(), cursor);
  MENU_IT it = listOptions.begin();
  for (int i = 0; i < 5; i++)
  {
    // display options
    if(it != listOptions.end())
    {
      (*it)->display(i);
      it++;
    }
    SCREEN.drawLine(0,32*i-1,127,32*i-1);    
  }
  SCREEN.drawLine(0,0,0,127);
  SCREEN.drawLine(0,0,127,0);
  SCREEN.drawLine(127,0,127,127);

  SCREEN.setFont(u8g2_font_unifont_t_symbols);
  SCREEN.drawGlyph(32, 32*pos+14, 0x25e4);
  SCREEN.drawGlyph(32, 32*(pos+1)-4, 0x25e3);
  SCREEN.drawGlyph(128-10, 32*pos+14, 0x25e5);
  SCREEN.drawGlyph(128-10, 32*(pos+1)-4, 0x25e2);
  
}

// Select an option.
void MenuDD::select()
{
  if (((OptionMenuDD*)(*cursor))->getMenuPtr() != nullptr)
  {
    menuStack.push(*currMenu);
    ((OptionMenuDD*)(*cursor))->getMenuPtr()->setCurrMenu();
    Serial.print("Select");
  }
}

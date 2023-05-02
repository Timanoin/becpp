#include "MenuDD.h"
#include <U8g2lib.h>

MenuDD::MenuDD(SCREEN* u8g2) : Menu(u8g2) {}

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
    u8g2->drawLine(0,32*i-1,127,32*i-1);    
  }
  u8g2->drawLine(0,0,0,127);
  u8g2->drawLine(0,0,127,0);
  u8g2->drawLine(127,0,127,127);

  u8g2->setFont(u8g2_font_unifont_t_symbols);
  u8g2->drawGlyph(32, 32*pos+14, 0x25e4);
  u8g2->drawGlyph(32, 32*(pos+1)-4, 0x25e3);
  u8g2->drawGlyph(128-10, 32*pos+14, 0x25e5);
  u8g2->drawGlyph(128-10, 32*(pos+1)-4, 0x25e2);
  
}
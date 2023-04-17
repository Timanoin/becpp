#include "MenuOption.h"
#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>

MenuOption::MenuOption(const char* text, unsigned char* icon, void (*func_ptr)(void), SCREEN* u8g2) : 
text(text), icon(icon), func_ptr(func_ptr), u8g2(u8g2){};

void MenuOption::display(int Y)
{
  u8g2->drawXBM(0,32*Y,32,32,icon);
  u8g2->drawStr(32,32*Y+24,text);
}
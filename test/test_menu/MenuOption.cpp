#include "MenuOption.h"
#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>

MenuOption(std::string text, char* icon, void (*func_ptr)(void)) : 
text(text), icon(icon), func_ptr(func_ptr){};

void MenuOption::display(int Y)
{
  u8g2.drawXBM(0,Y,32,32,icon)
  u8g2.Str(32,Y, text)
}
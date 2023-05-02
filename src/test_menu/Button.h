#ifndef __BUTTON__
#define __BUTTON__
#include <Arduino.h>

class Button{
  protected:
  int pin;
  bool state;
  bool output;

  public:
  Button(int pin);
  bool pushed();
  void update();
};

#endif
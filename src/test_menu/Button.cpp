#include "Button.h"

Button::Button(int pin): pin(pin), state(false)
{
  pinMode(pin, INPUT);
}
bool Button::pushed()
{
  return output;
}
void Button::update()
{
  if (digitalRead(pin) == HIGH)
  {
    if(!state)
    {
      output = true;
      state = true;
    }
    else
    {  
      output = false;
      // state = true;
    }
  }
  else
  {
    output = false;
    state = false;
  }
}
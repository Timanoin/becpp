#include "Button.h"

Button::Button(int pin): pin(pin), state(false)
{

}
bool Button::pushed()
{
  return output;
}
void Button::update()
{
  if (digitalRead(pin) && !state)
  {
    output = true;
    state = true;
  }
  else if (!digitalRead(pin))
  {
    output = false;
    state = false;
  }
  else{
    output = false;
    // state = true;
  }
}
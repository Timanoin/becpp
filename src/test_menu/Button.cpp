#include "Button.h"

// Constructor of class Button
// int pin : Pin used by the button on the Arduino
Button::Button(int pin): pin(pin), state(false)
{
  pinMode(pin, INPUT);
}

// Returns a positive pulse when the button is pushed.
bool Button::pushed()
{
  return output;
}

// Call this at every loop when using a button
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
#ifndef __BUTTON__
#define __BUTTON__
#include <Arduino.h>

class Button{
  protected:
  // Pin used by the button on the Arduino
  int pin;
  // Current state of the button
  bool state;
  // Output provided by the button
  bool output;

  public:
  // Constructor of class Button
  // int pin : Pin used by the button on the Arduino
  Button(int pin);
  // Returns a positive pulse when the button is pushed.
  bool pushed();
  // Call this at every loop when using a button
  void update();
};

#endif
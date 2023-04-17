#ifndef __BUTTON__
#define __BUTTON__

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
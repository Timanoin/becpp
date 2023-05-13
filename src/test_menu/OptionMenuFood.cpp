#include "OptionMenuFood.h"
#include "constants.h"

OptionMenuFood::OptionMenuFood(int index) : OptionMenu(nullptr, nullptr), index(index), cost(0)
{
  menuPtr = new MenuSelect(index);
}

OptionMenuFood::~OptionMenuFood()
{
  delete menuPtr;
}
void OptionMenuFood::display(int Y)
{
  SCREEN.drawXBM(0,0,128,96,icon);
  SCREEN.drawStr(8,96+24,text);
  std::string cost_text = std::to_string(cost);
  cost_text = cost_text.substr(0,cost_text.size()-4);
  SCREEN.drawStr(64+8,96+24,cost_text.c_str());
}

void OptionMenuFood::init()
{
  this->text = CART[index]->getName();
  this->icon = CART[index]->getIcon();
  this->cost = CART[index]->getCost();
}

// Get the next menu pointer.
Menu* OptionMenuFood::getMenuPtr()
{
  return menuPtr;
}
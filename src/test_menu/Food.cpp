#include "Food.h"

Food::Food(const char* name, unsigned char* icon, const char* desc1, const char* desc2, float cost) : 
           name(name), icon(icon), desc1(desc1), desc2(desc2), cost(cost)
{
  quantity = new int(0);
}
Food::~Food()
{
  delete quantity;
}

const char* Food::getName()
{
  return name;
}
unsigned char* Food::getIcon()
{
  return icon;
}
const char* Food::getDesc1()
{
  return desc1;
}
const char* Food::getDesc2()
{
  return desc2;
}
float Food::getCost()
{
  return cost;
}
int* Food::getQuantity()
{
  return quantity;
}
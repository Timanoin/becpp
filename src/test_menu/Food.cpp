#include "Food.h"

Food::Food(const char* name, unsigned char* icon, const char* desc, float cost) : 
           name(name), icon(icon), desc(desc), cost(cost)
{
  quantity = new unsigned int(0);
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
const char* Food::getDesc()
{
  return desc;
}
float Food::getCost()
{
  return cost;
}
unsigned int* Food::getQuantity()
{
  return quantity;
}
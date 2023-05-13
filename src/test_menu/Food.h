#ifndef __FOOD__
#define __FOOD__

class Food
{
  private:
  const char* name; 
  unsigned char* icon;
  const char* desc;
  float cost;
  unsigned int* quantity;

  public:
  Food(const char* name, unsigned char* icon, const char* desc, float price);
  ~Food();
  const char* getName();
  unsigned char* getIcon();
  const char* getDesc();
  float getCost();
  unsigned int* getQuantity();
};

#endif
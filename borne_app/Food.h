#ifndef __FOOD__
#define __FOOD__

class Food
{
  private:
  const char* name; 
  unsigned char* icon;
  const char* desc1;
  const char* desc2;
  float cost;
  int* quantity;

  public:
  Food(const char* name, unsigned char* icon, const char* desc1, const char* desc2, float price);
  ~Food();
  const char* getName();
  unsigned char* getIcon();
  const char* getDesc1();
  const char* getDesc2();
  float getCost();
  int* getQuantity();
};

#endif
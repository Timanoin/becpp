#ifndef __ARTICLE__
#define __ARTICLE__
#include "constants.h"
#include "MenuOption.h"
#include <list>


class Article
{
  protected:
  SCREEN* u8g2;
  int prix;
  static unsigned char image;
  String nom;

  public:
  Article(SCREEN* u8g2);
  ~Article();

  
  void init();
  virtual void display() = 0;

};

#endif
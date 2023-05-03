#ifndef __ARTICLE__
#define __ARTICLE__
#include "constants.h"
#include "MenuOption.h"
#include <list>


class Article
{
  protected:
  static unsigned char* icon;
  String name;
  String desc;
  int cost;

  public:
  Article();
  Article(static unsigned char* icon, String name, String desc, int cost);
  ~Article();

  virtual void display() = 0;
};

#endif
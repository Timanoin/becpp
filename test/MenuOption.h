#include <string>

class MenuOption
{
  protected:
  std::string txt;
  char* icon;
  void (*func_ptr)(void);

  public:
  MenuOption();
  void display(int x, int y);
};
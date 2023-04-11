#include <string>

class MenuOption
{
  protected:
  std::string text;
  char* icon;
  void (*func_ptr)(void);

  public:
  MenuOption();
  MenuOption(std::string text, char* icon, void (*func_ptr)(void));
  void display(int Y);
};
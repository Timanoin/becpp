#ifndef __CONSTANTS__
#define __CONSTANTS__

#include <U8g2lib.h>
#include "Food.h"
#include <map>

// Pins
#define PIN_BUTTON_NEXT D6
#define PIN_BUTTON_PREV D7
#define PIN_BUTTON_SELECT D5
#define PIN_BUTTON_BACK D8

// Screen
extern U8G2_SH1107_SEEED_128X128_1_SW_I2C SCREEN;
#define SCREEN_RESET_FONT()  SCREEN.setFont(u8g2_font_amstrad_cpc_extended_8f)
#define SCREEN_SYMBOL_FONT() SCREEN.setFont(u8g2_font_unifont_t_symbols)

// CART
extern std::map<int, Food*> CART;

enum FoodID {COLA, ICETEA, FANTA, CAFE,
      SALADE, JAMBON,
      PIZZA, BURGER, SUSHI, PATES, FRITES,
      GATEAU, GLACE, COOKIE,
      MENF, MVEGE, MJOUR,
      // do not add any IDs after this point
      IDLAST};
#endif
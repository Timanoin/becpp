#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include "MenuDD.h"
#include "image.h"
#include "constants.h"
#include "Button.h"

SCREEN u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
MenuDD m2(&u8g2);
MenuOption beta2_option("BETA", beta_bits, nullptr, &u8g2);
MenuDD m(&u8g2);
MenuOption beta_option("BETA", beta_bits, &m2, &u8g2);
MenuOption phi_option("PHI", phi_bits, nullptr, &u8g2);
MenuOption psi_option("PSI", psi_bits, nullptr, &u8g2);
MenuOption omega_option("OMEGA", omega_bits, nullptr, &u8g2);
Button bnext(PIN_BUTTON_NEXT);
Button bprev(PIN_BUTTON_PREV);
Button bselect(PIN_BUTTON_SELECT);
Button bback(PIN_BUTTON_BACK);

void setup(void) {
  u8g2.begin();
  m.addOption(&beta_option);
  m.addOption(&phi_option);
  m.addOption(&psi_option);
  m.addOption(&omega_option);
  u8g2.setFont(u8g2_font_ncenB12_tr);
  m.init();
  m.setCurrMenu();
}

void loop(void) {
  bnext.update();
  bprev.update();
  // select menu
  if (bnext.pushed())
  {
    Menu::currMenu.next();
  }
  else if (bprev.pushed())
  {
    Menu::currMenu.prev();
  }
  else if (bselect.pushed())
  {
    Menu::currMenu.select();
  }
  else if (bprev.back())
  {
    Menu::currMenu.back();
  }
  // display menu
  u8g2.firstPage();
  do {
    Menu::currMenu.display();  
  } while ( u8g2.nextPage() );
}
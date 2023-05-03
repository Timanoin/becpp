#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include "MenuDD.h"
#include "image.h"
#include "constants.h"
#include "Button.h"

U8G2_SH1107_SEEED_128X128_1_SW_I2C SCREEN(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
MenuDD m2;
MenuOption beta2_option("BETA2", beta_bits, nullptr);
MenuDD m3;
MenuOption beta3_option("BETA3", beta_bits, nullptr);
MenuDD m4;
MenuOption beta4_option("BETA4", beta_bits, nullptr);
MenuDD m;
MenuOption beta_option("BETA", beta_bits, &m2);
MenuOption phi_option("PHI", phi_bits, &m3);
MenuOption psi_option("PSI", psi_bits, &m4);
MenuOption omega_option("OMEGA", omega_bits, nullptr);
Button bnext(PIN_BUTTON_NEXT);
Button bprev(PIN_BUTTON_PREV);
Button bselect(PIN_BUTTON_SELECT);
Button bback(PIN_BUTTON_BACK);

void setup(void) {
  Serial.begin(9600);
  SCREEN.begin();
  m.addOption(&beta_option);
  m.addOption(&phi_option);
  m.addOption(&psi_option);
  m.addOption(&omega_option);
  m2.addOption(&beta2_option);
  m3.addOption(&beta3_option);
  m4.addOption(&beta4_option);
  SCREEN.setFont(u8g2_font_ncenB12_tr);
  m.init();
  m2.init();
  m3.init();
  m4.init();
  m.setCurrMenu();
}

void loop(void) {
  bnext.update();
  bprev.update();
  bselect.update();
  bback.update();
  // select menu
  if (bnext.pushed())
  {
    (*Menu::currMenu)->next();
  }
  else if (bprev.pushed())
  {
    (*Menu::currMenu)->prev();
  }
  else if (bselect.pushed())
  {
    (*Menu::currMenu)->select();
  }
  else if (bback.pushed())
  {
    (*Menu::currMenu)->back();
  }
  // display menu
  SCREEN.firstPage();
  do {
    (*Menu::currMenu)->display();  
  } while (SCREEN.nextPage());
}
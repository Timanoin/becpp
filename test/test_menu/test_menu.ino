#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include "MenuDD.h"
#include "image.h"
#include "constants.h"

SCREEN u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
MenuDD m(&u8g2);
MenuOption beta_option("BETA", beta_bits, nullptr, &u8g2);
MenuOption phi_option("PHI", phi_bits, nullptr, &u8g2);
MenuOption psi_option("PSI", psi_bits, nullptr, &u8g2);
MenuOption omega_option("OMEGA", omega_bits, nullptr, &u8g2);

void setup(void) {
  u8g2.begin();
  m.addOption(&beta_option);
  m.addOption(&phi_option);
  m.addOption(&psi_option);
  m.addOption(&omega_option);
  u8g2.setFont(u8g2_font_ncenB12_tr);
}

void loop(void) {
  u8g2.firstPage();
  do {
    m.display();  
  } while ( u8g2.nextPage() );
}
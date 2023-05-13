#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include "MenuDD.h"
#include "MenuFood.h"
#include "image.h"
#include "constants.h"
#include "Button.h"

#include <map>

U8G2_SH1107_SEEED_128X128_F_SW_I2C SCREEN(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

std::map<int, Food*> CART;

Food cola("Cola", cola_bits, "Coca Cola", 1.50);
Food icetea("Ice Tea", icetea_bits, "Lipton Ice \nTea", 1.50);
Food fanta("Fanta", fanta_bits, "Une boisson \ngazeuse.", 2.00);
Food cafe("Cafe", cafe_bits, "Cafe noir \n", 2.50);
Food salade("Salade", salade_bits, "Une salade \ncomposée", 7.00);
Food jambon("Jambon", jambon_bits, "Un jambon \nde porc", 9.00);
Food pizza("Pizza", pizza_bits, "Une pizza \nmargarita", 13.00);
Food burger("Burger", burger_bits, "Un Hamburger", 12.00);
Food sushi("Sushis", sushi_bits, "Assortiment de \nsushis", 12.00);
Food pates("Pates", pates_bits, "Plat de pates\n italiennes", 15.00);
Food frites("Frites", frites_bits, "Une barquette \nde frites", 1.50);
Food gateau("Gateau", gateau_bits, "Un fondant \nau chocolat", 7.50);
Food glace("Glace", glace_bits, "Un cornet \nVanille/chocolat", 5.00);
Food cookie("Cookie", cookie_bits, "Un cookie \ngenereux", 4.00);
Food enfant("Enfant", burger_bits, "burger, frites, \nglace, cola", 18.00);
Food vegetarien("Vegetarien", salade_bits, "Salade, pizza \ncookie", 19.00);
Food jour("Du Jour", cola_bits, "Jambon, Pates, \n Gateau", 21.00);

MenuFood boissons_menu;
OptionMenuFood cola_option(COLA);
OptionMenuFood icetea_option(ICETEA);
OptionMenuFood fanta_option(FANTA);
OptionMenuFood cafe_option(CAFE);
MenuFood entrees_menu;
OptionMenuFood salade_option(SALADE);
OptionMenuFood jambon_option(JAMBON);
MenuFood plats_menu;
OptionMenuFood pizza_option(PIZZA);
OptionMenuFood burger_option(BURGER);
OptionMenuFood sushi_option(SUSHI);
OptionMenuFood pates_option(PATES);
OptionMenuFood frites_option(FRITES);
MenuFood desserts_menu;
OptionMenuFood gateau_option(GATEAU);
OptionMenuFood glace_option(GLACE);
OptionMenuFood cookie_option(COOKIE);
MenuFood menus_menu;
OptionMenuFood enfant_option(MENF);
OptionMenuFood vegetarien_option(MVEGE);
OptionMenuFood classique_option(MJOUR);
MenuDD carte_menu;
OptionMenuDD entrees_option("Entrees", entrees_bits, &entrees_menu);
OptionMenuDD plats_option("Plats", plats_bits, &plats_menu);
OptionMenuDD desserts_option("Desserts", desserts_bits, &desserts_menu);
OptionMenuDD boissons_option("Boissons", boissons_bits, &boissons_menu);
MenuDD main_menu;
OptionMenuDD carte_option("Carte", carte_bits, &carte_menu);
OptionMenuDD menus_option("Menus", menus_bits, &menus_menu);
OptionMenuDD panier_option("Panier", panier_bits, nullptr);

Button bnext(PIN_BUTTON_NEXT);
Button bprev(PIN_BUTTON_PREV);
Button bselect(PIN_BUTTON_SELECT);
Button bback(PIN_BUTTON_BACK);

void setup(void) {
  Serial.begin(9600);
  SCREEN.begin();
  CART[COLA]   = &cola;
  CART[ICETEA] = &icetea;
  CART[FANTA]  = &fanta;
  CART[CAFE]   = &cafe;
  CART[SALADE] = &salade;
  CART[JAMBON] = &jambon;
  CART[PIZZA]  = &pizza;
  CART[BURGER] = &burger;
  CART[SUSHI]  = &sushi;
  CART[PATES]  = &pates;
  CART[FRITES] = &frites;
  CART[GATEAU] = &gateau;
  CART[GLACE]  = &glace;
  CART[COOKIE] = &cookie;
  CART[MENF]   = &enfant;
  CART[MVEGE]  = &vegetarien;
  CART[MJOUR]  = &jour;
  main_menu.addOption(&carte_option);
  main_menu.addOption(&menus_option);
  main_menu.addOption(&panier_option);
  carte_menu.addOption(&entrees_option);
  carte_menu.addOption(&plats_option);
  carte_menu.addOption(&desserts_option);
  carte_menu.addOption(&boissons_option);
  boissons_menu.addOption(&cola_option);
  boissons_menu.addOption(&icetea_option);
  boissons_menu.addOption(&fanta_option);
  boissons_menu.addOption(&cafe_option);
  entrees_menu.addOption(&salade_option);
  entrees_menu.addOption(&jambon_option);
  plats_menu.addOption(&pizza_option);
  plats_menu.addOption(&burger_option);
  plats_menu.addOption(&sushi_option);
  plats_menu.addOption(&pates_option);
  plats_menu.addOption(&frites_option);
  desserts_menu.addOption(&gateau_option);
  desserts_menu.addOption(&glace_option);
  desserts_menu.addOption(&cookie_option);
  menus_menu.addOption(&enfant_option);
  menus_menu.addOption(&vegetarien_option);
  menus_menu.addOption(&classique_option);
  main_menu.init();
  carte_menu.init();
  boissons_menu.init();
  plats_menu.init();
  desserts_menu.init();
  entrees_menu.init();
  menus_menu.init();
  main_menu.setCurrMenu();
}

void loop(void) {
  SCREEN.clearBuffer();
  SCREEN.setFont(u8g2_font_ncenB10_tr);
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
  (*Menu::currMenu)->display(); 
  SCREEN.sendBuffer(); 
}
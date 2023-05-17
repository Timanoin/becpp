#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "MenuDD.h"
#include "MenuFood.h"
#include "MenuCart.h"
#include "image.h"
#include "constants.h"
#include "Button.h"


#include <map>
//-------------------------------------------------//
//               WIFI COMMUNICATION                //
//-------------------------------------------------//
/* paramètres connexion wifi à la carte esp8266 */
const char* ssid = "NodeMCU";  // nom du SSID
const char* password = "12345678";  //mot de passe
/* adresse IP et passerelle*/
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

std::string cart_string = "";
int temps_estime = 0;
int pbm1 = 0;

bool sent_command = false;

//-------------------------------------------------//
//                  OTHER OBJECTS                  //
//-------------------------------------------------//
U8G2_SH1107_SEEED_128X128_1_SW_I2C SCREEN(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

std::map<int, Food*> CART;

Food cola("Cola", cola_bits, "Coca Cola", "", 2.00);
Food icetea("Ice Tea", icetea_bits, "Lipton Ice Tea", "", 2.00);
Food fanta("Fanta", fanta_bits, "Fanta Orange", "", 2.00);
Food cafe("Cafe", cafe_bits, "Cafe noir", "", 1.00);
Food salade("Salade", salade_bits, "Salade", "composee", 8.00);
Food jambon("Jambon", jambon_bits, "2 tranches","de jambon", 5.00);
Food pizza("Pizza", pizza_bits, "Margherita","", 10.00);
Food burger("Burger", burger_bits, "Hamburger", "au boeuf", 8.00);
Food sushi("Sushis", sushi_bits, "Assortiment", "de sushis", 12.00);
Food pates("Pates", pates_bits, "Pates", "bolognaises", 12.00);
Food frites("Frites", frites_bits, "Barquette", "de frites", 3.50);
Food gateau("Gateau", gateau_bits, "Fondant au", "chocolat", 5.50);
Food glace("Glace", glace_bits, "Cornet vanille", "chocolat", 6.00);
Food cookie("Cookie", cookie_bits, "Cookie", "max size", 4.00);
Food enfant("Enfant", burger_bits, "Burger, frites,", "glace, cola", 15.00);
Food vegetarien("Vege", salade_bits, "Salade, pizza,", "cookie, cola", 21.50);
Food jour("Du Jour", pates_bits, "Jambon, pates,", "gateau, cafe", 18.50);

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
OptionMenuDD entrees_option( "Entrees" , entrees_bits , &entrees_menu , nullptr);
OptionMenuDD plats_option(   "Plats"   , plats_bits   , &plats_menu   , nullptr);
OptionMenuDD desserts_option("Desserts", desserts_bits, &desserts_menu, nullptr);
OptionMenuDD boissons_option("Boissons", boissons_bits, &boissons_menu, nullptr);
MenuCart panier_menu;
MenuDD main_menu;
OptionMenuDD carte_option("Carte"  , carte_bits , &carte_menu , nullptr);
OptionMenuDD menus_option("Menus"  , menus_bits , &menus_menu , nullptr);
OptionMenuDD panier_option("Panier", panier_bits, &panier_menu, nullptr);
void sendCommand();
OptionMenuDD sendcommand_option("Commander", dollar_bits, nullptr, sendCommand);

Button bnext(PIN_BUTTON_NEXT);
Button bprev(PIN_BUTTON_PREV);
Button bselect(PIN_BUTTON_SELECT);
Button bback(PIN_BUTTON_BACK);

void setup(void) {
//-------------------------------------------------//
//                SERVER CONNECTION                //
//-------------------------------------------------//
  WiFi.mode(WIFI_AP);
  Serial.begin(115200);
  //lancement du serveur wifi
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(200);
  

  //définit les fonctions à exécuter suivant les requêtes URL
  server.on("/", handle_OnConnect);
  server.on("/t_5", t_5);
  server.on("/t_10", t_10);
  server.on("/t_20", t_20);
  server.on("/pbm", pbm);
  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("Serveur HTTP démarré");

//-------------------------------------------------//
//                  OTHER OBJECTS                  //
//-------------------------------------------------//
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
  main_menu.addOption(&sendcommand_option);
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
//-------------------------------------------------//
//                  SERVER START                   //
//-------------------------------------------------//
  server.handleClient();
  Serial.println("loop");
//-------------------------------------------------//
//                  OTHER OBJECTS                  //
//-------------------------------------------------//
  SCREEN_RESET_FONT();
  bnext.update();
  bprev.update();
  bselect.update();
  bback.update();
  // select menu
  if (bnext.pushed())
  {
    (*Menu::currMenu)->next();
  }
  // move cursor down
  else if (bprev.pushed())
  {
    (*Menu::currMenu)->prev();
  }
  // move cursor up
  else if (bselect.pushed())
  {
    (*Menu::currMenu)->select();
  }
  // go back 1 layer of menu
  else if (bback.pushed())
  {
    (*Menu::currMenu)->back();
  }
  SCREEN.firstPage();
  do {
  // display menu
  (*Menu::currMenu)->display(); 
  // decoration
  SCREEN.drawLine(0,0,0,127);
  SCREEN.drawLine(0,0,127,0);
  SCREEN.drawLine(127,0,127,127);
  SCREEN.drawLine(0,127,127,127);
  // send image to screen
  } while ( SCREEN.nextPage() ); 
}

std::string format_cart()
{
  cart_string = "<table>\n <thead>\n <tr>\n <th colspan=\"2\">Commande borne 1</th>\n </tr>\n </thead>\n";
  cart_string += "<tbody>\n";
  for (int i = 0; i < IDLAST;  i++)
  {
    if (*(CART[i]->getQuantity()) > 0)
    {
      cart_string += "<tr>\n";
      cart_string += "<td> ";
      cart_string += CART[i]->getName();
      cart_string += "</td>\n";
      cart_string += "<td>";
      cart_string += std::to_string((int)(*(CART[i]->getQuantity())));
      cart_string += "</td>\n";
      cart_string += "</tr>\n";
    }
  }
  cart_string += "</tbody>\n </table>\n";
  return cart_string;
}


void handle_OnConnect() {  
  server.send(200, "text/html", (String)(SendHTML(temps_estime).c_str())); 
}

void t_5() {
  temps_estime = 5;
  pbm1 = 0;
  server.send(200, "text/html", (String)(SendHTML(temps_estime).c_str())); 
}

void t_10() {
  temps_estime = 10;
  pbm1 = 0;
  server.send(200, "text/html", (String)(SendHTML(temps_estime).c_str())); 
}

void t_20() {
  temps_estime = 20;
  pbm1 = 0;
  server.send(200, "text/html", (String)(SendHTML(temps_estime).c_str())); 
}

void pbm() {
 
  pbm1 = 1;
  server.send(200, "text/html", (String)(SendHTML(temps_estime).c_str())); 
}


void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

std::string SendHTML(int temps_estime){
  std::string ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>CART TABLE 1</title>\n";
  ptr +="<meta http-equiv=refresh content=20>";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 20px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 10px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #FF0000;}\n";
  ptr +=".button-on:active {background-color: ##DC143C;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  if (sent_command)
  {
    ptr +="<h1>TABLE 1</h1>\n";
    ptr +="<h3>COMMANDE :</h3>\n";
    // affichage du panier
    ptr +="<h3>";
    ptr += format_cart().c_str() ;
    ptr += "</h3>\n";
  }
  ptr +="<h3>Temps estim&eacute :</h3>\n";
  
  // Bouton pour choisir la durée
  ptr +="<a class=\"button button-off\" href=\"/t_5\">5 minutes</a>\n";
  ptr +="<a class=\"button button-off\" href=\"/t_10\">10 minutes</a>\n";
  ptr +="<a class=\"button button-off\" href=\"/t_20\">20 minutes</a>\n";

  ptr +="<a class=\"button button-on\" href=\"/pbm\">Erreur commande</a>\n";
  if (pbm1==1)
  {
      ptr +="<h3>Erreur commande</h3>\n";
  }
  else 
  {
    ptr +="<h3>Temps estim&eacute :</h3>\n";
    ptr +="<h3>";
    ptr += std::to_string(temps_estime).c_str();
    ptr +="</h3>\n";
  }


  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}

void sendCommand()
{
  if (sent_command) 
  {
    sent_command = false;
  }
  else
  {
    sent_command = true;
  }
}
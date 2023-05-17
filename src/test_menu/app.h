#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* paramètres connexion wifi à la carte esp8266 */
const char* ssid = "NodeMCU";  // nom du SSID
const char* password = "12345678";  //mot de passe
/* adresse IP et passerelle*/
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

//définition des variables
String panier = "aucune";
int t = 0;
int pbm1 = 0;

bool sent_command = false;


//--------fonction initialisation (exécuté qu'une fois au lancement du programme)
void setup() {
  //taux de transfert de la liaison série
  Serial.begin(115200);
  //lancement du serveur wifi
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  

  //définit les fonctions à exécuter suivant les requêtes URL
  server.on("/", handle_OnConnect);
  server.on("/t_5", t_5);
  server.on("/t_10", t_10);
  server.on("/t_20", t_20);
  server.on("/pbm", pbm);
  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("Serveur HTTP démarré");
}
//-------Programme principal
void loop() {
  //--récupère les événements du serveur
  server.handleClient();
  //--panier les sorties
  if(LEDstatus)
  {digitalWrite(LEDpin, HIGH);}
  else
  {digitalWrite(LEDpin, LOW);}
}

//fonction exécutée à chaque chargement de la page web
void handle_OnConnect() {  
  server.send(200, "text/html", SendHTML(t, panier)); 
}

void t_5() {
  LEDstatus = LOW;
  t = 5;
  pbm1 = 0;
  server.send(200, "text/html", SendHTML(t, panier)); 
}

void t_10() {
  LEDstatus = LOW;
  t = 10;
  pbm1 = 0;
  server.send(200, "text/html", SendHTML(t, panier)); 
}

void t_20() {
  LEDstatus = LOW;
  t = 20;
  pbm1 = 0;
  server.send(200, "text/html", SendHTML(t, panier)); 
}

void pbm() {
  LEDstatus = HIGH;
  pbm1 = 1;;
  server.send(200, "text/html", SendHTML(t, panier)); 
}


void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(int t, String panier){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
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
    ptr +="<h3>" + (String)panier + "</h3>\n";
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
    ptr +="<h3>" + (String)t + "</h3>\n";
  }


  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
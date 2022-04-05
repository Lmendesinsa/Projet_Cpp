#include <ESP8266WiFi.h>


void setup()
{
  Serial.begin(115200); // initialisation de la connexion serie (terminal)
  WiFi.begin("Laura", "Antolebest");

  Serial.print("Connection en cours");
  while (WiFi.status() != WL_CONNECTED) // tant que l'esp n'est pas connecté au réseau on attends
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connecté, adresse IP : ");
  Serial.println(WiFi.localIP()); // affichage de l'adresse IP
}

void loop(){
  
}

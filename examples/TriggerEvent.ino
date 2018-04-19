/*******************************************************************
 *  Trigger event at end of the setup                              *
 *                                                                 *
 *  adapted by Brian Lough
 *
 *          changed by enindza                                      *
 *******************************************************************/

#include <IFTTTwebhooks.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#include "local.h"
// content of local.h
// comment out #include #include "local.h"
//------- Uncomment the following! and replace with your data ------
/*char ssid[] = "xxx";       // your network SSID (name)
char password[] = "yyyy";  // your network key
#define KEY "zzzzzzzzzzzzzzzzzzzzzzz"  // Get it from this page https://ifttt.com/services/maker_webhooks/settings
#define EVENT_NAME "device_on" // Name of your event name, set when you are creating the applet
*/

IFTTTwebhooks* client = nullptr;

void setup() {

  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  Serial.printf("Free heap0: %u\n", ESP.getFreeHeap());

  // Use IFTTTwebhooks class to create a new TLS connection
  client = new IFTTTwebhooks(KEY);

  //triggerEvent takes an Event Name and then you can optional pass in up to 3 extra Strings
  if(client->triggerEvent(EVENT_NAME, ssid, ip.toString())){
    Serial.println("IFTTT Successfully sent");
  } else
  {
    Serial.println("IFTTT Failed!");
  }
  Serial.printf("Free heap1: %u\n", ESP.getFreeHeap());

// delete IFTTTwebhooks object
  delete client;
  client = nullptr;
  Serial.printf("Free heap2: %u\n", ESP.getFreeHeap());
}

void loop() {
}

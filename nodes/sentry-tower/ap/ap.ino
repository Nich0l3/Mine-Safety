#include <ESP8266WiFi.h>

IPAddress local_IP(192,168,4,2);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);

// Set AP credentials
#define AP_SSID "Mine-Net"
#define AP_PASS ""

#define DEVICE 10

// Set WiFi credentials
//#define WIFI_SSID ""
//#define WIFI_PASS ""


void setup()
{
  //WiFi.mode(WIFI_AP_STA);

  Serial.begin(115200);

  Serial.print("Setting soft-AP configuration ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

  Serial.print("Setting modes ... ");
  
  // Begin Access Point
  WiFi.softAP(AP_SSID, AP_PASS,1,0,DEVICE);
  
  // Begin WiFi
  //WiFi.begin(WIFI_SSID, WIFI_PASS);
}

void loop() {
  Serial.print("IP address for network ");
  Serial.print(AP_SSID);
  Serial.print(" : ");
  Serial.print(WiFi.softAPIP());
//  Serial.print("IP address for network ");
//  Serial.print(WIFI_SSID);
//  Serial.print(" : ");
//  Serial.println(WiFi.localIP());

  Serial.print("\n\n");

  delay(5000);  

}

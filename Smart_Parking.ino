#include "ESP8266WiFi.h"
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
// Set these to run 
#define FIREBASE_HOST "carrotkun-smart-parking-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "osBrSDOViZeJxnIUdNB6LVK2dVLDRtjrMS6OPM1r"
#define WIFI_SSID "A6/9"
#define WIFI_PASSWORD "Nov1234.a"


 int trigPin1 = 16;
 int echoPin1 = 5;
 int trigPin2 = 4;
 int echoPin2 = 0;
 int trigPin3 = 14;
 int echoPin3 = 12;
 int parkingslot = 3;

void setup() {
  Serial.begin(9600); // Starts the serial communication
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
  Serial.print("ichi ni san shi, Let's go!!!!");
  
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
}

void loop() {
  parkingslot = 3;
 int waktu1, jarak1;
 digitalWrite(trigPin1,LOW);delay(10);
 digitalWrite(trigPin1,HIGH);delay(10);digitalWrite(trigPin1,LOW);
 waktu1 = pulseIn(echoPin1,HIGH); //microsecond
 jarak1 = (waktu1/2) / 29.1; // centimeter
 Serial.print(jarak1);
 Serial.println(" cm1");
 delay(100);     

 int waktu2, jarak2;
 digitalWrite(trigPin2,LOW);delay(10);
 digitalWrite(trigPin2,HIGH);delay(10);digitalWrite(trigPin2,LOW);
 waktu2 = pulseIn(echoPin2,HIGH); //microsecond
 jarak2 = (waktu2/2) / 29.1; // centimeter
 Serial.print(jarak2);
 Serial.println(" cm2");
 delay(100);

  int waktu3, jarak3;
  digitalWrite(trigPin3,LOW);delay(10);
  digitalWrite(trigPin3,HIGH);delay(10);digitalWrite(trigPin3,LOW);
  waktu3 = pulseIn(echoPin3,HIGH); //microsecond
  jarak3 = (waktu3/2) / 29.1; // centimeter
  Serial.print(jarak3);
  Serial.println(" cm3");
  delay(100);
  
 if(jarak1 < 15){
   parkingslot = parkingslot - 1;
   Firebase.setString("message1","Full");
 }else{
   Firebase.setString("message1","Empty");
 }

 if(jarak2 < 15){
   parkingslot = parkingslot - 1;
   Firebase.setString("message2","Full");
 }else{
   Firebase.setString("message2","Empty");
 }

  if(jarak3 < 15){
    parkingslot = parkingslot - 1;
    Firebase.setString("message3","Full");
  }else{
    Firebase.setString("message3","Empty");
  }

  Serial.print("parking available ");
  Serial.println(parkingslot);

  Firebase.setFloat("Parking slot available", parkingslot);
  // handle error
  if (Firebase.failed()) {
      Serial.print("Update failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  delay(200);
}

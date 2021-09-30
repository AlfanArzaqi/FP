#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

#define buzzerPin D4

int state = 0;
int potValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (buzzerPin, OUTPUT);
  digitalWrite (buzzerPin, LOW);
  Serial.begin (115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    state = Serial.read();
  }

  if (state == '1'){
    digitalWrite (buzzerPin, HIGH);
    tone (buzzerPin, 500);
    delay (1000);
    state = 0;
  }

  else if (state == '0'){
    digitalWrite (buzzerPin, LOW);
    state = 0;
  }

}

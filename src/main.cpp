#include <Arduino.h>
#include <SoftwareSerial.h>

const int RS_RX = 9;
const int RS_TX = 8;
const int RS_RTS = 10;
SoftwareSerial RS_Slave(RS_RX, RS_TX);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  RS_Slave.begin(9600);
  pinMode(RS_RTS, OUTPUT);
  digitalWrite(RS_RTS, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (RS_Slave.available())
  {
    Serial.write(RS_Slave.read());
  }
}


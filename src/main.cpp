#include <Arduino.h>
#include <SoftwareSerial.h>

const int RS_RX = 7;
const int RS_TX = 8;
const int RS_RTS = 10;
SoftwareSerial RS_Slave(RS_RX, RS_TX);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  RS_Slave.begin(9600);
  pinMode(RS_RTS, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(RS_RTS, LOW);
  while(!Serial)
  {
    delay(1);
  }
  Serial.println("Starting");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(RS_Slave.available());
  digitalWrite(LED_BUILTIN, LOW);
  if (RS_Slave.available())
  {
    //digitalWrite(LED_BUILTIN, HIGH);
    Serial.write(RS_Slave.read());

    if (Serial.available())
    {
      digitalWrite(RS_RTS, HIGH);
      RS_Slave.write(Serial.read());
      digitalWrite(RS_RTS, LOW);
    }
  }
}


// #include <Arduino.h>

// const int RS_DE_RE = 10;  // RS485 DE/RE pin (Always LOW for Slave)
// const int RECEIVED_LED = 13; // LED indicator for received data

// void setup() {
//     Serial.begin(9600);   // USB Serial for debugging
//     Serial1.begin(9600);  // Use Serial1 instead of SoftwareSerial

//     pinMode(RS_DE_RE, OUTPUT);
//     digitalWrite(RS_DE_RE, LOW); // Always in receive mode

//     pinMode(RECEIVED_LED, OUTPUT);
//     digitalWrite(RECEIVED_LED, LOW); // LED off initially
//     while(!Serial){
//       delay(1);
//     }
//     Serial.println("RS485 Slave Ready (Receiving Only)");
// }

// void loop() {
//     if (Serial1.available()) {
//         char incomingData = Serial1.read();

//         Serial.print("Slave Received: ");
//         Serial.println(incomingData);

//         // Blink LED to indicate data reception
//         digitalWrite(RECEIVED_LED, HIGH);
//         delay(100);
//         digitalWrite(RECEIVED_LED, LOW);
//     }
// }



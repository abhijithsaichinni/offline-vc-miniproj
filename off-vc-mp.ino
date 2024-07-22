
#include <Servo.h>
unsigned int receivedValue = 0;
#define relay1 A0
#define relay2 A1
#define relay3 A2
#define relay4 A3
Servo myservo;  // create servo object to control a servo


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);
  //while (!Serial); // wait for serial port to connect. Needed for native USB port only, this port is for displaying data Grove Sensor sends

  // Serial.println("USB Serial Port connection Established!");

  // Set the data rate for the SoftwareSerial port - Grove Offline Voice Recognition Module runs at 9600 baud rate
}

void loop() {

  if (Serial.available()) {
    Serial.println("Data From VC-02");
    // Read the incoming bytes
    byte highByte = Serial.read();
    byte lowByte = Serial.read();

    // Combine the two bytes into a single 16-bit value
    receivedValue = (highByte << 8) | lowByte;

    // Print the received value in HEX format
    Serial.print("Received HEX value: 0x");
    Serial.println(receivedValue, HEX);
  }

  if (receivedValue == 0xA190)  // Check if the value is A2 in HEX
  {
    myservo.write(90);  // sets the servo position according to the scaled value
    delay(15);
  } else if (receivedValue == 0xA145) {
    myservo.write(45);  // sets the servo position according to the scaled value
    delay(15);
  } else if (receivedValue == 0xBB01) {
    digitalWrite(relay1, HIGH);  // sets the gpio pin on/off
    delay(15);
  } else if (receivedValue == 0xBB02) {
    digitalWrite(relay2, HIGH);  // sets the gpio pin on/off
    delay(15);
  } else if (receivedValue == 0xBB03) {
    digitalWrite(relay3, HIGH);  // sets the gpio pin on/off
    delay(15);
  } else if (receivedValue == 0xBB04) {
    digitalWrite(relay4, HIGH);  // sets the gpio pin on/off
    delay(15);
  } else if (receivedValue == 0xCC01) {
    digitalWrite(relay1, LOW);  // sets the gpio pin on/off
    delay(15);
  } else if (receivedValue == 0xCC02) {
    digitalWrite(relay2, LOW);  // ssets the gpio pin on/off
    delay(15);
  } else if (receivedValue == 0xCC03) {
    digitalWrite(relay3, LOW);  // sets the gpio pin on/off
    delay(15);
  } else if (receivedValue == 0xCC04) {
    digitalWrite(relay4, LOW);  // sets the gpio pin on/off
    delay(15);
  } else {
  }
  delay(10);
  receivedValue = 0;
}

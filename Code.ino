#include <SoftwareSerial.h>

// Define the pins for the flex sensors
#define FLEX_PIN1 A0
#define FLEX_PIN2 A1
#define FLEX_PIN3 A2
#define FLEX_PIN4 A3

// Bluetooth module pins
#define BT_RX 10
#define BT_TX 11

// Initialize the software serial port
SoftwareSerial Bluetooth(BT_RX, BT_TX);

void setup() {
  // Begin serial communication with the computer
  Serial.begin(9600);

  // Begin serial communication with the Bluetooth module
  Bluetooth.begin(9600);

  // Set the flex sensor pins as input
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN2, INPUT);
  pinMode(FLEX_PIN3, INPUT);
  pinMode(FLEX_PIN4, INPUT);
}

void loop() {
  // Read the analog values from the flex sensors
  int flex1 = analogRead(FLEX_PIN1);
  int flex2 = analogRead(FLEX_PIN2);
  int flex3 = analogRead(FLEX_PIN3);
  int flex4 = analogRead(FLEX_PIN4);

  // Print the flex sensor values to the serial monitor
  Serial.println("");
  Serial.print("F1: ");
  Serial.println(flex1);
  Serial.print("F2: ");
  Serial.println(flex2);
  Serial.print("F3: ");
  Serial.println(flex3);
  Serial.print("F4: ");
  Serial.println(flex4);
  Serial.print(" ");

  // Check the conditions and print messages accordingly
  if ((951 <= flex1 && flex1 <= 964) || (52 <= flex1 && flex1 <= 58) || (-253 <= flex2 && flex2 <= -251) || (-73 <= flex3 && flex3 <= 62)) {
    Bluetooth.print("Hello");
    Serial.print("Hello");
  }
  if ((894 <= flex1 && flex1 <= 908) || (1017 <= flex2 && flex2 <= 1019) || (-171 <= flex1 && flex1 <= -155) || (-193 <= flex2 && flex2 <= -181) || (-55 <= flex3 && flex3 <= -39)) {
    Bluetooth.print("Pencil");
    Serial.print("Pencil");
  }
 
  if (374 <= flex1 && flex1 <= 428 && 788 < flex4 && flex4 < 815 && 138 <= flex1 && flex1 <= 158 && -115 <= flex2 && flex2 <= -98 && 130 <= flex3 && flex3 <= 153) {
    Bluetooth.print("Question");
    Serial.print("Question");

  if (330 <= flex1 && flex1 <= 410 && 788 < flex4 && flex4 < 815 && 120 <= flex1 && flex1 <= 131 && -135 <= flex2 && flex2 <= -98 && 160 <= flex3 && flex3 <= 173) {
    Bluetooth.print("Answer");
    Serial.print("Answer");
  }
  if (140 <= flex1 && flex1 <= 210 && 568 < flex4 && flex4 < 715 && 160 <= flex1 && flex1 <= 131 && -185 <= flex2 && flex2 <= -98 && 120 <= flex3 && flex3 <= 173) {
    Bluetooth.print("New Learning");
    Serial.print("New Learning");
  }
  if (160 <= flex1 && flex1 <= 220 && 568 < flex4 && flex4 < 715 && 160 <= flex1 && flex1 <= 180 && -185 <= flex2 && flex2 <= -98 && 220 <= flex3 && flex3 <= 373) {
    Bluetooth.print("Give me water");
    Serial.print("Give me water");
  } else {
    Bluetooth.print("nothing");
    Serial.print("nothing");
  }

  Bluetooth.print("New value");
  Serial.print("New value");

  // Delay for 2 seconds before the next loop iteration
  delay(2000);
}
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Servo.h>

// Create the Player object
DFRobotDFPlayerMini player;
// Use pins 10 and 11 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 11; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 10; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

//Create servo object
Servo myservo;
// Define pin and delay for the servo
int servoPin = 13; 
int d=1000;

// Define the pins for the buttons
const int buttonPin1 = 2;     // the number of the pushbutton1 pin
const int buttonPin2 = 3;     // the number of the pushbutton2 pin
const int buttonPin3 = 4;     // the number of the pushbutton3 pin

// Define the pins for the leds
const int ledPin1 =  5;       // the number of the LED1 pin
const int ledPin2 =  6;       // the number of the LED2 pin
const int ledPin3 =  7;       // the number of the LED3 pin

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton1 status
int buttonState2 = 0;         // variable for reading the pushbutton2 status
int buttonState3 = 0;         // variable for reading the pushbutton3 status

void setup() {
// Start communication with DFPlayer Mini
  if (player.begin(softwareSerial))  {
    Serial.println("OK");
     } 
     else 
     {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
   
  // initialize the LED pins as outputs:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  
  // Init USB serial port for debugging
  Serial.begin(9600);
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);

  // Attach servo to servoPin
  myservo.attach(servoPin);
    
// Set volume to maximum (0 to 30).
    player.volume(20);

// -------------------------------------------------------------
// read the state of the pushbuttons:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  
  // Check if a pushbutton is pressed. If it is, the corresponding buttonState is HIGH and the corresponding LED lights up:
  
  // Check for button 1
  if (buttonState1 == HIGH) 
  {
    // turn LED1 on:
    digitalWrite(ledPin1, HIGH);  // Light LED 1
    player.play(1);               // Play track 1
  myservo.write(45);              // Move servo 3 times
  delay(d); 
  myservo.write(135); 
  delay(d); 
  myservo.write(45);
  delay(d); 
  myservo.write(135); 
  delay(d); 
  myservo.write(45);
  delay(d); 
  myservo.write(135); 
  delay(d); 
  } 
   else 
  { 
    // turn LED 1 off:
    digitalWrite(ledPin1, LOW);
  }
//Check for button 2 - LED 2
     if (buttonState2 == HIGH) {
    // turn LED2 on:
    digitalWrite(ledPin2, HIGH);  // Light LED 2
    player.play(2);               // Play track 2
  myservo.write(45);              // Move servo 3 times
  delay(d); 
  myservo.write(135); 
  delay(d); 
  myservo.write(45);
  delay(d); 
  myservo.write(135); 
  delay(d); 
  myservo.write(45);
  delay(d); 
  myservo.write(135); 
  delay(d); 
  }  
  else 
  {
    // turn LED 2 off:
    digitalWrite(ledPin2, LOW);
  }
// Check for button 3
  if (buttonState3 == HIGH) 
  {
    // turn LED3 on:
    digitalWrite(ledPin3, HIGH);  // Light LED 3
    player.play(3);               // Play track 3
  myservo.write(45);              // Move servo 3 times
  delay(d); 
  myservo.write(135); 
  delay(d); 
  myservo.write(45);
  delay(d); 
  myservo.write(135); 
  delay(d); 
  myservo.write(45);
  delay(d); 
  myservo.write(135); 
  delay(d); 
  }
  else 
    {
    // turn LED 3 off:
    digitalWrite(ledPin3, LOW);
    }

}void loop(){
}

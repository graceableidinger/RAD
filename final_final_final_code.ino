
/*  Getting_BPM_to_Monitor prints the BPM to the Serial Monitor, using the least lines of code and PulseSensor Library.
 *  Tutorial Webpage: https://pulsesensor.com/pages/getting-advanced
 *
--------Use This Sketch To------------------------------------------
1) Displays user's live and changing BPM, Beats Per Minute, in Arduino's native Serial Monitor.
2) Print: "♥  A HeartBeat Happened !" when a beat is detected, live.
2) Learn about using a PulseSensor Library "Object".
4) Blinks the builtin LED with user's Heartbeat.
--------------------------------------------------------------------*/

#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   

//  Variables
const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
int Threshold = 100;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
                               
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"

int motorPin = 3; //motor transistor is connected to pin 3
double mins = 100;  // holds the incoming raw data. Signal value can range from 0-1024
double mil;
bool wakeUpTime = false;

void setup() {   

  Serial.begin(9600);          // For Serial Monitor

  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }
}



void loop() {

if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened".
int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 
 Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
 Serial.print("BPM: ");                        // Print phrase "BPM: " 
 Serial.println(myBPM);  
 if (!wakeUpTime) { // if the specified time has not been reached
    Serial.print(mins);
    if (mins>-1) { // if the user has inputted a time
      Serial.print("mins is");
      Serial.println(mins);
      mil = mins*60000;
      if (millis()>= mil) { // if the current time matches the specified time
        wakeUpTime = true; // set the boolean to true
        Serial.println("The time has been reached!");
      }
    }
 }
   if(myBPM > Threshold || wakeUpTime){ 
    Serial.println("high");// If the signal is above "550", then "turn-on" Arduino's on-Board LED.
    digitalWrite(motorPin,HIGH);
  } 
  else{
    Serial.println("low");
    digitalWrite(motorPin,LOW);  //  Else, the signal must be below "550", so "turn-off" this LED.
  }
// Print the value inside of myBPM. 
}

  delay(5);                    // considered best practice in a simple sketch.

}

  


#include <Wire.h>
#include <MIDI.h>
#include <Servo.h>

struct CustomBaud : public midi::DefaultSettings{
    //static const long BaudRate = 31250; // Baud rate for midi
    static const long BaudRate = 115200; // Baud rate for midi
};

MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI,CustomBaud ); // Serial1

int strenth = 0;

const int COIL01 = 2;
const int COIL02 = 3;
const int COIL03 = 4;
const int COIL04 = 5;
const int COIL05 = 6;
const int COIL06 = 7;

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo
int servoPin1 = 8;
int servoPin2 = 9;
int servoPin3 = 10;
int servoPin4 = 11;


void setup()
{

    myservo1.attach(servoPin1); 
    myservo1.write(80);
    myservo2.attach(servoPin2); 
    myservo2.write(80);
    myservo3.attach(servoPin3); 
    myservo3.write(85);
    myservo4.attach(servoPin3); 
    myservo4.write(85);
    
  
    pinMode(COIL01, OUTPUT);
    pinMode(COIL02, OUTPUT);
    pinMode(COIL03, OUTPUT);
    pinMode(COIL04, OUTPUT);
    pinMode(COIL05, OUTPUT);
    pinMode(COIL06, OUTPUT);
    //Serial.begin(115200);
    MIDI.begin(3); // DECLARE MIDI ch
    MIDI.turnThruOn();
    MIDI.setHandleNoteOn(HandleNoteOn);
    MIDI.setHandleNoteOff(HandleNoteOff);
}
    
  void loop() {
    MIDI.read(); 
}

void HandleNoteOn (byte channel, byte number, byte velocity) {
 
  if (number == 60) { 
  analogWrite(COIL01, 255);
  }
  if (number == 61) { 
  analogWrite(COIL02, 255);
  }
  if (number == 62) { 
  analogWrite(COIL02, 255);
  }
  if (number == 63) { 
  analogWrite(COIL03, 255);
  }
  if (number == 64) { 
  analogWrite(COIL04, 255);
  }
  if (number == 65) { 
  analogWrite(COIL05, 255);
  }
  if (number == 66) { 
  analogWrite(COIL06, 255);
  }
  //////////////SERVOS///////////////////
  
  if (number == 67) { 
  myservo1.write(75);             
  }  
  if (number == 68) {
  myservo1.write(60);           
  }  
  if (number == 69) { 
    myservo2.write(75);             
  }  
  if (number == 70) { 
    myservo2.write(60);             
  }
  if (number == 71) { 
    myservo3.write(80);             
  }  
  if (number == 72) { 
    myservo3.write(70);             
  }
  if (number == 73) { 
    myservo4.write(80);             
  }  
  if (number == 74) { 
    myservo4.write(70);            
  }
}   
  
void HandleNoteOff(byte channel, byte number, byte velocity) { 

  if (number == 60) {
  analogWrite(COIL01, 0);
  }
  if (number == 61) {
  analogWrite(COIL02, 0);
  }
  if (number == 62) { 
  analogWrite(COIL02, 0);
  }
  if (number == 63) { 
  analogWrite(COIL03, 0);
  }
  if (number == 64) { 
  analogWrite(COIL04, 0);
  }
  if (number == 65) { 
  analogWrite(COIL05, 0);
  }
  if (number == 66) { 
  analogWrite(COIL06, 0);
  }
   
}

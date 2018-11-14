
//#include <Wire.h>
#include <MIDI.h>
#include <Servo.h>

struct CustomBaud : public midi::DefaultSettings{
    //static const long BaudRate = 31250; // Baud rate for midi
    static const long BaudRate = 115200; // Baud rate for midi
};

MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI,CustomBaud ); // Serial1

int strenth = 0;

Servo myservo1;  // create servo object to control a servo
int servoPin1 = 8;



void setup()
{

    myservo1.attach(servoPin1); 
    myservo1.write(110);
   
    
    MIDI.begin(4); // DECLARE MIDI ch
    Serial.begin(115200);
    MIDI.turnThruOn();
    MIDI.setHandleNoteOn(HandleNoteOn);
    MIDI.setHandleNoteOff(HandleNoteOff);
}
    
  void loop() {
    MIDI.read(); 
}

void HandleNoteOn (byte channel, byte number, byte velocity) {
  
  if (number == 67) { 
  myservo1.write(60);             
  }  
  if (number == 68) {
  myservo1.write(115);           
  }  
}   
  
void HandleNoteOff(byte channel, byte number, byte velocity) { 

  
   
}

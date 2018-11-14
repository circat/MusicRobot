
//#include <Wire.h>
#include <MIDI.h>

struct CustomBaud : public midi::DefaultSettings{
    //static const long BaudRate = 31250; // Baud rate for midi
    static const long BaudRate = 115200; // Baud rate for midi
};
//MIDI_CREATE_DEFAULT_INSTANCE();
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI,CustomBaud ); // Serial1 on MEGA


const int COIL01 = 2;
const int COIL02 = 3;
const int COIL03 = 4;
const int COIL04 = 5;
const int COIL05 = 6;
const int COIL06 = 7;
const int COIL07 = 8;
const int COIL08 = 9;
const int COIL09 = 10;
const int COIL10 = 11;
const int COIL11 = 12;
const int COIL12 = 13;
const int COIL13 = 14;

void setup()
{
pinMode(COIL01, OUTPUT);
    pinMode(COIL02, OUTPUT);
    pinMode(COIL03, OUTPUT);
    pinMode(COIL04, OUTPUT);
    pinMode(COIL05, OUTPUT);
    pinMode(COIL06, OUTPUT);
    pinMode(COIL07, OUTPUT);
    pinMode(COIL08, OUTPUT);
    pinMode(COIL09, OUTPUT);
    pinMode(COIL10, OUTPUT);
    pinMode(COIL11, OUTPUT);
    pinMode(COIL12, OUTPUT);
    pinMode(COIL13, OUTPUT);

    MIDI.begin(1); // DECLARE MIDI ch1
    //MIDI.turnThruOff();
   // Serial.begin(38400); // FOR DEBUG
    MIDI.turnThruOn();
    //Serial.begin(115200);
    //Serial1.begin(31250); // MIDI IN / 31250 BAUD ON SERIAL1
    //Serial1.begin(15625);
    MIDI.setHandleNoteOn(HandleNoteOn); // CALLBACKZ
   MIDI.setHandleNoteOff(HandleNoteOff);// CALLBACKZ
}
    
void loop()
{
 MIDI.read(); 
}

void HandleNoteOn (byte channel, byte number, byte velocity) { // ON MIDI NOTE ON DO

 // strenth = map(velocity, 0, 127, 200, 255); //35, seems to be the right value for putting all the coils on at velocity 127
 //////////////////////////
  if (number == 36) {
  analogWrite(COIL01, 255);
  } 
  if (number == 37) {
  analogWrite(COIL02, 255);

  } 
  if (number == 38) {
  analogWrite(COIL03, 255);

  }
   
  if (number == 39) {
  analogWrite(COIL04, 255);

  } 
  if (number == 40) {
  analogWrite(COIL05, 255);
 
  } 

  if (number == 41) {
  analogWrite(COIL06, 255);

  } 

  if (number == 42) {
  analogWrite(COIL07, 255);

  } 

  if (number == 43) {
  analogWrite(COIL08, 255);

  } 

  if (number == 44) {
  analogWrite(COIL09, 255);

  } 

  if (number == 45) {
  analogWrite(COIL10, 255);

  } 

  if (number == 46) {
  analogWrite(COIL11, 255);
 
  } 

  if (number == 47) {
  analogWrite(COIL12, 255);

  } 
   if (number == 48) {
  analogWrite(COIL13, 255);

  }
}

   void HandleNoteOff(byte channel, byte number, byte velocity) { 

  if (number == 36) {
  analogWrite(COIL01, 0);
  } 
  if (number == 37) {
  analogWrite(COIL02, 0);

  } 
  if (number == 38) {
  analogWrite(COIL03, 0);

  }
   
  if (number == 39) {
  analogWrite(COIL04, 0);

  } 
  if (number == 40) {
  analogWrite(COIL05, 0);
 
  } 

  if (number == 41) {
  analogWrite(COIL06, 0);

  } 

  if (number == 42) {
  analogWrite(COIL07, 0);

  } 

  if (number == 43) {
  analogWrite(COIL08, 0);

  } 

  if (number == 44) {
  analogWrite(COIL09, 0);

  } 

  if (number == 45) {
  analogWrite(COIL10, 0);

  } 

  if (number == 46) {
  analogWrite(COIL11, 0);
 
  } 

  if (number == 47) {
  analogWrite(COIL12, 0);

  } 
  if (number == 48) {
  analogWrite(COIL13, 0);

  }
  
}

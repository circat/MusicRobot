
//#include <Wire.h>
#include <MIDI.h>

struct CustomBaud : public midi::DefaultSettings{
    //static const long BaudRate = 31250; // Baud rate for midi
    static const long BaudRate = 115200; // Baud rate for midi
};

MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI,CustomBaud ); // Serial1 on MEGA

int strenth = 0;

const int AIR = 11;
const int COIL01 = 3; // C
const int COIL02 = 4; // C#
const int COIL03 = 5; // D
const int COIL04 = 6; // D#
const int COIL05 = 7;
const int COIL06 = 8;
const int COIL07 = 9;
const int COIL08 = 10;
const int COIL09 = 2;
const int COIL10 = 12;
const int COIL11 = 13;
const int COIL12 = 14;
const int COIL13 = 15;

void setup()
{
  
    pinMode(AIR, OUTPUT);
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

    MIDI.begin(2); // DECLARE MIDI2
    MIDI.turnThruOn();
    Serial.begin(115200);
    MIDI.setHandleNoteOn(HandleNoteOn); 
   MIDI.setHandleNoteOff(HandleNoteOff);
   MIDI.setHandleControlChange(handleControlChange);
}
    
void loop()
{
 MIDI.read(); 
}

void HandleNoteOn (byte channel, byte number, byte velocity) { // ON MIDI NOTE ON DO

  //strenth = map(velocity, 0, 127, 200, 255); //35, seems to be the right value for putting all the coils on at velocity 127
 
  if (number == 48) {
  analogWrite(COIL01, 255);
  } 
  if (number == 49) {
  analogWrite(COIL02, 255);
}   

if (number == 50) {
  analogWrite(COIL03, 255);
}
if (number == 51) {
  analogWrite(COIL04, 255);
}
if (number == 52) {
  analogWrite(COIL05, 255);
}
if (number == 53) {
  analogWrite(COIL06, 255);
}
if (number == 54) {
  analogWrite(COIL07, 255);
}
if (number == 55) {
  analogWrite(COIL08, 255);
}
if (number == 56) {
  analogWrite(COIL09, 255);
}
if (number == 57) {
  analogWrite(COIL10, 255);
}
if (number == 58) {
  analogWrite(COIL11, 255);
}
if (number == 59) {
  analogWrite(COIL12, 255);
}
if (number == 60) {
  analogWrite(COIL13, 255);
}
}

void HandleNoteOff(byte channel, byte number, byte velocity) { 

  if (number == 48) {
  analogWrite(COIL01, LOW);
  } 
  if (number == 49) {
  analogWrite(COIL02, LOW);
}   

if (number == 50) {
  analogWrite(COIL03, LOW);
}
if (number == 51) {
  analogWrite(COIL04, LOW);
}
if (number == 52) {
  analogWrite(COIL05, LOW);
}
if (number == 53) {
  analogWrite(COIL06, LOW);
}
if (number == 54) {
  analogWrite(COIL07, LOW);
}
if (number == 55) {
  analogWrite(COIL08, LOW);
}
if (number == 56) {
  analogWrite(COIL09, LOW);
}
if (number == 57) {
  analogWrite(COIL10, LOW);
}
if (number == 58) {
  analogWrite(COIL11, LOW);
}
if (number == 59) {
  analogWrite(COIL12, LOW);
}
if (number == 60) {
  analogWrite(COIL13, LOW);
}
 
}

void handleControlChange(byte channel, byte number, byte value){
  
if(number==1){
      int air = map(value,0,127,0,255);
      analogWrite(AIR, air);
  
  }
  }
